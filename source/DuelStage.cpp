#include "DuelStage.h"

DuelStage::DuelStage(void) {
    //create Text Manager Instance:
    this->myTextManager = new TextManager(0, BG_TEXT);

	this->aliveBandits = 3;

	//load imagery for duel stage:
	UIManager::LoadSprites(LEVEL_DUEL);
}

DuelStage::~DuelStage(void) {
	PA_ResetSpriteSys(); //clear all sprites and such
	PA_ClearBg(0, BG_DUEL_STAGE);
}


void DuelStage::DrawStage() {
	//load BG
	PA_LoadBackground(0, BG_DUEL_STAGE, &bg_duelStage);

	//draw bandits
	//bandit1
	UIManager::ShowSprite(SP_CHAR_DUEL_BANDIT1, 33, 55);
	UIManager::ShowSprite(SP_CHAR_DUEL_BANDIT1+1, 33, 119);

	//bandit2
	UIManager::ShowSprite(SP_CHAR_DUEL_BANDIT2, 98, 55);
	UIManager::ShowSprite(SP_CHAR_DUEL_BANDIT2+1, 98, 119);

	//bandit3
	UIManager::ShowSprite(SP_CHAR_DUEL_BANDIT3, 162, 55);
	UIManager::ShowSprite(SP_CHAR_DUEL_BANDIT3+1, 162, 119);
}

void DuelStage::PrintCountDown() {
	char text[1] = "";

	for(s8 x=5; x>-1; x--) {
		sprintf(text, "%d", x);
		this->myTextManager->PrintText(15, 1, text, false);
		sleep(1.4);
	}
}

void DuelStage::RunDuel(ReturnCode* _arrCodes) {
	ReturnCode retCode;

	this->DrawStage();	//draw stage + bandits
	//this->PrintCountDown(); //start countDown
		
	//get 3 instances of 'DuelBanditStatus' struct
	DuelBanditStatus arrBanditStatus[3];
	arrBanditStatus[0] = this->GetBanditStatusInstance();
	arrBanditStatus[1] = this->GetBanditStatusInstance();
	arrBanditStatus[2] = this->GetBanditStatusInstance();

	//duel 'main loop':
	u8 loopStatus = LOOP_RUNNING;
	while(loopStatus == LOOP_RUNNING) {

		//process player input
		retCode = {-1, -1};
		this->ProcessPlayerInput(arrBanditStatus, &retCode);
		
		//check if each one of theb three bandits wants to withdraw/shoot depending on its status
		for (int i = 0; i < 3; i++) {
			//only process if current bandit is still alive
			if (arrBanditStatus[i].alive) {
				//check if bandit wants to withdraw his gun
				if (arrBanditStatus[i].readyToWithdraw && !arrBanditStatus[i].withdrawed) {
					//draw bandit withdrawing his gun:
					this->DrawBanditWithdrawal(i);
					arrBanditStatus[i].withdrawed = true;
				} else {
					//check if bandit wants to shoot (has already withdrawed his gun)
					if (arrBanditStatus[i].readyToShoot && !arrBanditStatus[i].shoot) {
						//bandit killed player.
						retCode.code = GAME_DUEL_DIED;
						arrBanditStatus[i].shoot = true;
					}
				}
		
				//update banditActions
				this->UpdateBanditActiveCounter(&arrBanditStatus[i]);
			}
		}

		if (this->aliveBandits == 0 || (retCode.code > 0 && retCode.code != GAME_DUEL_KILL) ) {
			loopStatus = LOOP_EXIT;
		}

		//needed since its an independent loop (not part of main game loop):
		PA_WaitForVBL();
	}

	if (this->aliveBandits == 0) {
		retCode.code = GAME_DUEL_WON;
	}

	//set the returning code to the Game class:
	_arrCodes[0].code = retCode.code;
}

DuelBanditStatus DuelStage::GetBanditStatusInstance() {
	DuelBanditStatus stDuelBanditStatus;

	stDuelBanditStatus.alive = true;
	stDuelBanditStatus.withdrawed = false;
	stDuelBanditStatus.shoot = false;
	stDuelBanditStatus.readyToShoot = false; 
	stDuelBanditStatus.readyToWithdraw = false;	//initially, bandit has not drawed its gun
	stDuelBanditStatus.timeoutDrawGun = PA_RandMinMax(70, 300);	//randomize bandit timeout to withdraw gun
	stDuelBanditStatus.timeoutShootGun = PA_RandMinMax(40, 130);	//randomize bandit timeout to shoot gun

	return stDuelBanditStatus;
}

void DuelStage::UpdateBanditActiveCounter(DuelBanditStatus* _banditStatus) {
	//nothing to be updated in case bandit has already shoot:
	if ( _banditStatus->shoot ) {
		return;
	}

	//if has not drawed gun yet, decrease drawGun counter:
	if (_banditStatus->timeoutDrawGun > 0) {
		_banditStatus->timeoutDrawGun--;
	//else, decrease shootGun counter:
	} else {
		_banditStatus->readyToWithdraw = true;
		_banditStatus->timeoutShootGun--;
	}

	if (_banditStatus->timeoutShootGun == 0) {
		_banditStatus->readyToShoot = true;
	}
}


void DuelStage::ProcessPlayerInput(DuelBanditStatus* _banditStatus, ReturnCode* _code) {
	s8 btnY, btnX, btnB, btnA = -1;
	u8 banditPos; //0, 1 or 2

	//any button clicked?
	//Y		: Bandit on the LEFT
	//B,X	: Bandit on the MIDDLE
	//A		: Bandit on the RIGHT
	if ( (btnY = Pad.Newpress.Y) || (btnB = Pad.Newpress.B) || (btnX = Pad.Newpress.X) || (btnA = Pad.Newpress.A) ) {

		//determine bandit position from pressed keypad button
		if ( btnY > 0 ) {
			banditPos = 0;
		} else if ( btnB > 0 || btnX > 0 ) {
			banditPos = 1;
		} else if ( btnA > 0 ) {
			banditPos = 2;
		}

		//only process if current bandit is still alive
		if (_banditStatus[banditPos].alive) {
			//if corresponding bandit has not withdrawed his gun yet, player lose life
			if (!_banditStatus[banditPos].withdrawed) {
				_code->code = GAME_DUEL_KILL_INNOCENT;
				this->DrawBanditDying(banditPos, false);
				
			//else, kill bandit 
			} else {
				_banditStatus[banditPos].alive = false; // sign that bandit was killed
				_code->code = GAME_DUEL_KILL;
				this->DrawBanditDying(banditPos, true);
				this->aliveBandits--;
			}
		}
	}
}

void DuelStage::DrawBanditWithdrawal(u8 _banditPos) {
	u8 oldSpriteId = SP_CHAR_DUEL_BANDIT1;
	u8 newSpriteId = SP_CHAR_DUEL_BANDIT1 + 2;
	u8 posX = 33;

	switch(_banditPos) {
		case 1: 
			oldSpriteId = SP_CHAR_DUEL_BANDIT2;
			newSpriteId = SP_CHAR_DUEL_BANDIT2 + 2; 
			posX = 96;
			break;
		case 2: 
			oldSpriteId = SP_CHAR_DUEL_BANDIT3;
			newSpriteId = SP_CHAR_DUEL_BANDIT3 + 2; 
			posX = 160;
			break;
	}

	//hide old sprite and show the withdraw one:
	UIManager::HideSprite(oldSpriteId);
	UIManager::ShowSprite(newSpriteId, posX, 55);
}

void DuelStage::DrawBanditDying(u8 _banditPos, bool _withdrawedGun) {
	u8 posX = 25;
	u8 oldSpriteId = SP_CHAR_DUEL_BANDIT1;
	u8 newSpriteId = SP_CHAR_DUEL_BANDIT1_DYING;
	u8 bgSpriteId = SP_CHAR_DUEL_BANDIT1_BG;

	if ( _withdrawedGun ) {
		oldSpriteId = SP_CHAR_DUEL_BANDIT1_WITHDRAW;
	}

	switch(_banditPos) {
		case 1: 
			if ( _withdrawedGun ) {
				oldSpriteId = SP_CHAR_DUEL_BANDIT2_WITHDRAW;
			} else {
				oldSpriteId = SP_CHAR_DUEL_BANDIT2;
			}
			newSpriteId = SP_CHAR_DUEL_BANDIT2_DYING; 
			bgSpriteId = SP_CHAR_DUEL_BANDIT2_BG;
			posX = 89;
			break;

		case 2: 
			if ( _withdrawedGun ) {
				oldSpriteId = SP_CHAR_DUEL_BANDIT3_WITHDRAW;
			} else {
				oldSpriteId = SP_CHAR_DUEL_BANDIT3;
			}
			newSpriteId = SP_CHAR_DUEL_BANDIT3_DYING; 
			bgSpriteId = SP_CHAR_DUEL_BANDIT3_BG;
			posX = 153;
			break;
	}

	//hide current person's sprite:
	UIManager::HideSprite(oldSpriteId);

	//show 'sky' background:
	UIManager::ShowSprite(bgSpriteId, posX, 55);

	//show dying anim:
	UIManager::ShowSprite(newSpriteId, posX, 78);
	PA_StartSpriteAnimEx(0, newSpriteId, 0, 1, SPEED_DYING, ANIM_UPDOWN, 1);
}

//delete all loaded backgrounds and reset sprite system
void DuelStage::ClearStage() {
	PA_ResetSpriteSys(); //clear all sprites and such
	PA_ClearBg(0, BG_TEXT);
	PA_DeleteBg(0, BG_DUEL_STAGE);
	PA_DeleteBg(0, BG_BANG);
}