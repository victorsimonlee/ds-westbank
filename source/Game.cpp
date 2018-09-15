#include "Game.h"


Game::Game(void) {
	//init Game variables
	this->myGameLevel = 1;
	this->myLives = 3;
	this->myScore = 0;

	//call static UIManager to load all level sprites at once!
	UIManager::LoadSprites(this->myGameLevel);

    //create Text Manager:
    this->myTextManager = new TextManager(0, BG_TEXT);

	//create main stage class:
	this->myMainStage = new MainStage();


	//load game-wide SFX:
	mmLoadEffect(SFX_BANG);
	mmLoadEffect(SFX_SHOOT);
	mmLoadEffect(SFX_MONEY);
	mmLoadEffect(SFX_BOOM);
}

//unload resources
Game::~Game() {
	mmUnloadEffect(SFX_BANG);
	mmUnloadEffect(SFX_SHOOT);
	mmUnloadEffect(SFX_MONEY);
	mmUnloadEffect(SFX_BOOM);
	PA_ResetSpriteSys();
}


//start the game on a certain level
u8 Game::Run(u8 _level) {
	bool nextLevel = false;
	bool lostLife = false;

	while(true) {
		//play current level music
		this->PlayLevelMusic(this->myGameLevel);
	
		//set current level on global LevelManager object
		::levelManager.SetCurrentLevel(this->myGameLevel);

		//show start phase screen
		ShowPhaseScreen(this->myGameLevel);

		//draw main stage background
		this->myMainStage->DrawStage();

		//print player lifes
		this->PrintLifes();

		//Level loop
		while(!nextLevel && !lostLife) {
			//print current score
			this->PrintScore();

			this->RunDuelStage(1);

			//process doors (initialize an array of returnCode)
			ReturnCode myDoorReturningCodes[3] {{-1,-1}, {-1,-1}, {-1,-1}};
			this->myMainStage->ProcessDoors(myDoorReturningCodes);

			//calculates score, draw 'bang','boom' screens, update life counter, etc - depending on the returning code
			this->ProcessReturningCodes(myDoorReturningCodes);
			
			//lost life?
			if ( this->GetPlayerLostLife(myDoorReturningCodes) ) {
				//YES
				lostLife = true;
			} else {

				//NO .. go to next phase? (all doors closed and with money flag?)
				if ( this->myMainStage->GetAllDoorsWaiting() && this->myMainStage->GetAllDoorsWithMoney() ) {
					//YES
						//blink dollar signs
						this->myMainStage->BlinkDollarSigns();
						sleep(2);

						//run Duel stage
						nextLevel = this->RunDuelStage(this->myGameLevel);

				} else {
					//NO .. process player input
					ReturnCode myDoorReturningCodes[3] {{-1,-1}, {-1,-1}, {-1,-1}};
					this->myMainStage->ProcessPlayerInput(myDoorReturningCodes);
					
					//calculates score, draw 'bang','boom' screens, update life counter, etc - depending on the returning code
					this->ProcessReturningCodes(myDoorReturningCodes);

                    lostLife = this->GetPlayerLostLife(myDoorReturningCodes);
				}
			}
			PA_WaitForVBL();
		}

		//if died, reset variables
		if (!nextLevel) {
			lostLife = false;
		} else {
			this->myGameLevel++;
			nextLevel = false;
		}

		//check if is a game_over:
		if (this->myLives == 0) {
			break;
		}
	}

	//ENTERNAME case will determine if user has made enough points
	return MAIN_LOOP_ENTERNAME;
}


bool Game::RunDuelStage(u8 _level) {
	//clean up memory and graphics used by mainStage:
	this->myMainStage->ResetStage();

	//create/loads the duel stage:
	DuelStage *aDuelStage = new DuelStage();
	
	this->ShowPhaseScreen(0); //0 = The Duel phase

	//print player lifes
	this->PrintLifes();

	//print player score
	this->PrintScore();

	ReturnCode aDuelReturningCodes[3] { {-1,-1}, {-1,-1}, {-1,-1} };
	aDuelStage->RunDuel(aDuelReturningCodes);

	//calculates score, draw 'bang','boom' screens, update life counter, etc - depending on the returning code
	this->ProcessReturningCodes(aDuelReturningCodes);

	//unload the duel stage:
	delete(aDuelStage);

	//DuelStage uses only the 1st position in the array:
	return (aDuelReturningCodes[0].code == GAME_DUEL_DIED) || (aDuelReturningCodes[0].code == GAME_DUEL_KILL_INNOCENT);
}

//display text with current level
void Game::ShowPhaseScreen(u8 _level) {
	char lvlText[7] = "level ";

	if (_level == 0) {
		this->myTextManager->PrintText(12, 11, (char *)"the duel");
	} else {
		switch(_level){
			case 1: lvlText[6] = '1'; break;
			case 2: lvlText[6] = '2'; break;
			case 3: lvlText[6] = '3'; break;
			case 4: lvlText[6] = '4'; break;
			case 5: lvlText[6] = '5'; break;
		}
		this->myTextManager->PrintText(12, 11, (char *)lvlText);
	}

	sleep(1.5);
	PA_ClearBg(0, BG_TEXT);
	sleep(1);
}

//update total score with points earned from a call to 'ProcessDoors' (for each door)
void Game::ProcessReturningCodes(ReturnCode _arrReturnCodes[]) {
	for (u8 x=0; x<3; x++) {
		if ( _arrReturnCodes[x].code > -1 ) {
			switch(_arrReturnCodes[x].code) {

				case GAME_BANG:  //bandit shoot
					//stop music
					this->StopLevelMusic(this->myGameLevel);
					this->myMainStage->ResetStage();	//reset the stage in order to restart level

					//play bang sound & draw bang screen
					mmEffect(SFX_BANG);
					UIManager::DrawBangScreen();
					
					//load all sprites again
					UIManager::LoadSprites(this->myGameLevel);

					this->myLives--;
					break;
					
				case GAME_KILL_BOMB:
					this->StopLevelMusic(this->myGameLevel);
					this->myMainStage->ResetStage();	//reset the stage in order to restart level

					//play bang sound & draw bang screen
					mmEffect(SFX_BOOM);
					UIManager::DrawBoomScreen();
					
					//load all sprites again
					UIManager::LoadSprites(this->myGameLevel);

					this->myLives--;
				break;

				case GAME_KILL_INNOCENT:
					this->StopLevelMusic(this->myGameLevel);

					//blinks life sprite:
					UIManager::PlayLostLifeAnimation(this->myLives);

				    //reset the stage in order to restart level
					this->myMainStage->ResetStage();
					sleep(1.3);

					//load all sprites again
					UIManager::LoadSprites(this->myGameLevel);

					this->myLives--;
                break;
                
				case GAME_DUEL_WON:
				//player won duel?
				//YES
					//increment currentPhase counter
					//go to next phase
					break;
				

				case GAME_DUEL_DIED:
					PA_ResetSpriteSys(); //clear all sprites and such
					PA_ClearBg(0, BG_TEXT);
					PA_DeleteBg(0, BG_DUEL_STAGE);
					PA_DeleteBg(0, BG_BANG);
					
					//play bang sound & draw bang screen
					mmEffect(SFX_BANG);
					UIManager::DrawBangScreen();
					this->myLives--;
					break;

				case GAME_DUEL_KILL_INNOCENT:
					//blinks life sprite:
					UIManager::PlayLostLifeAnimation(this->myLives);
					this->myLives--;
					break;


				case GAME_KILL_MONEY:
				case GAME_KILL_HAT:
				case GAME_KILL_BANDIT:
				case GAME_MONEY:
					this->myScore += ::levelManager.GetScoreFor(_arrReturnCodes[x].code, _arrReturnCodes[x].person);
					break;
			}
		}
	}
}

void Game::PrintLifes() {
	u8 x;
	u8 xPosition = 180;

	//first, hide all life sprites:
	for (x = 0; x <= this->myLives; x++)
		UIManager::HideSprite(SP_LIFE+x);

	//print sprites for remaining lives
	for (x = 0; x < this->myLives; x++) {
		UIManager::ShowSprite(SP_LIFE+x, xPosition, 170);

		xPosition += 18;
	}
}

void Game::PrintScore() {
	char text[6] = "";

	sprintf(text, "%06d", this->myScore);
	this->myTextManager->PrintText(8, 22, text);
}

//check if a door returned a GAME_ code indicating player lost a life
bool Game::GetPlayerLostLife(ReturnCode _arrReturnCodes[]) {
	for (u8 x = 0; x < 3; x++) {
		if ( _arrReturnCodes[x].code == GAME_BANG || _arrReturnCodes[x].code == GAME_KILL_BOMB || 
			_arrReturnCodes[x].code == GAME_KILL_INNOCENT || _arrReturnCodes[x].code == GAME_DUEL_DIED || 
			_arrReturnCodes[x].code == GAME_DUEL_KILL_INNOCENT) {
				return true;
		}
	}
	return false;
}

//check if player has advanced to next level
bool Game::GetPlayerAdvancedLevel(ReturnCode _arrReturnCodes[]) {
	for (u8 x = 0; x < 3; x++) {
		if ( _arrReturnCodes[x].code == GAME_NEXT_LEVEL ) {
			return true;
		}
	}
	return false;
}

void Game::PlayLevelMusic(u8 _level) {
	switch(_level) {
		case 1:
			mmLoad(MOD_LEVEL1);
			mmSetModuleVolume(380); //this music is too loud...
			mmStart(MOD_LEVEL1, MM_PLAY_LOOP);
			break;

		case 2:

			break;

		case 3:

			break;
	}
}

void Game::StopLevelMusic(u8 _level) {
	mmSetModuleVolume(1024); //full volume

	switch(_level) {
		case 1:
			mmStop();
			mmUnload(MOD_LEVEL1);
			break;

		case 2:

			break;

		case 3:

			break;
	}
}