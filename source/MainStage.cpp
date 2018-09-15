/* vvvvvvvvvvvvvvvvvvvvvvvvvvv INCLUDES vvvvvvvvvvvvvvvvvvvvvvvvvvvvvv */
//includes for graphics
#include "all_gfx.h"

#include "MainStage.h"
/* vvvvvvvvv MAXMOD vvvvvvvvvv */
#include <maxmod9.h>
// Include the soundbank
#include "soundbank_bin.h"
#include "soundbank.h"
/* ^^^^^^^^^ MAXMOD ^^^^^^^^^^ */
/* ^^^^^^^^^^^^^^^^^^^^^^^^^^^ INCLUDES ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^ */

MainStage::MainStage() {
	for (int x = 0; x < 12; x++)
		this->myDoors[x] = new Door(x);

	//the first door is the active one
	this->myCurrentDoor = 0;

	//initialize position property of first 3 doors on screen:
	this->myDoors[0]->SetPosition(0);
	this->myDoors[1]->SetPosition(1);
	this->myDoors[2]->SetPosition(2);

	//initialize random wait for each door:
	PA_InitRand(); //start random seed
	for ( u8 x = 0; x < 12; x++ ) {
		this->myDoors[x]->SetWaiting(PA_RandMinMax(1, MAX_WAIT_TIME));
	}

	//load stage-wide SFX
	mmLoadEffect(SFX_MAN_DIE);
	mmLoadEffect(SFX_BANDIT_DIE);
}

MainStage::~MainStage(void) {
	mmUnloadEffect(SFX_MAN_DIE);
	mmUnloadEffect(SFX_BANDIT_DIE);
}

void MainStage::ProcessDoors(ReturnCode* _arrCodes) {
	Door *aDoor = NULL;

	//do the processing on current door + 2 (doors 1,2,3 ...)
	for (u8 x = this->myCurrentDoor; x < this->myCurrentDoor + 3; x++) {
	//for (u8 x = 0; x < 2; x++) { //for debug purposes..
		aDoor = this->myDoors[x];

		//door closed or waiting?
		if ( (aDoor->GetStatus() == DOOR_CLOSED) || (aDoor->GetStatus() == DOOR_WAITING) ) {
			
			//yes .. door can be opened (is in state closed) ?
			if ( aDoor->GetStatus() == DOOR_CLOSED ) {
				//yes. Start open door animation
				aDoor->Open();
			}

		} else {
			//No. Door just closed?
			if ( aDoor->GetStatus() == DOOR_JUST_CLOSED ) {
				
				//YES... //there is a live client behind door?
				if ( aDoor->IsPersonCustomer() && aDoor->IsPersonAlive() ) {
					//print current door's "money" flag
					this->RegisterDoorMoney(aDoor->GetID());
					aDoor->SetMoneyFlag(true);

					//set ReturnCode with: code = "money", person = door->GetCurrentPerson()
					_arrCodes[aDoor->GetPosition()] = { GAME_MONEY, aDoor->GetCurrentPerson() };
				}
				
			} else {
				//NO. Door open?
				if ( aDoor->GetStatus() == DOOR_OPEN ) {
					
					//YES. read DoorOpen Counter. Counter equal ZERO?
					if ( aDoor->GetOpenCounter() == 0 ) {
						//YES.
						
						//char is bandit? AND is ALIVE?
						if ( aDoor->IsPersonAlive() && aDoor->IsPersonBandit() ){
							//Yes. BANG! you're dead (return "BANG" code)
							_arrCodes[aDoor->GetPosition()] = { GAME_BANG, -1 };

						} else {
							//No. Close door
							aDoor->Close();
						}
					}
				}
			}
		}

		//tell door to update its status (must be called just ONCE per VBL)
		aDoor->UpdateStatus();
	}
}

void MainStage::ProcessPlayerInput(ReturnCode* _arrCodes) {
	s8 left, right = -1;
	s8 btnY, btnX, btnB, btnA = -1;
	Door* aDoor = NULL;

	///////////////////////////////////////// KEYPAD //////////////////////////////////////////////////
	//left/right keypad?
	if ( (left = Pad.Newpress.Left) || (right = Pad.Newpress.Right) ) {
		//YES .. all doors waiting?
		if ( this->GetAllDoorsWaiting() ) {
			//YES .. scroll doors to correct direction
			if ( left > 0 ) {
				this->Scroll(SCROLL_LEFT);
			} else if ( right > 0 ) {
				this->Scroll(SCROLL_RIGHT);
			}
		}
	}
	////////////////////////////////////////// BUTTONS //////////////////////////////////////////////////
	//any button clicked?
	if ( (btnY = Pad.Newpress.Y) || (btnB = Pad.Newpress.B) || (btnX = Pad.Newpress.X) || (btnA = Pad.Newpress.A) ) {
		//YES
		aDoor = this->GetDoorByPressedButton(btnY, btnX, btnB, btnA);

		//display 'shoot' sprite & play SFX
		mmEffect(SFX_SHOOT);
		UIManager::DrawShoot(aDoor->GetPosition());

		//hit door is OPEN and person is ALIVE?
		if ( aDoor->GetStatus() == DOOR_OPEN && aDoor->IsPersonAlive() ) {
			//char is bandit?
			if ( aDoor->IsPersonBandit() ) {
				//YES .. return KILL_BANDIT code
				//set ReturnCode with: code = "KILL_BANDIT", person = door->GetCurrentPerson()
				_arrCodes[aDoor->GetPosition()] = { GAME_KILL_BANDIT, aDoor->GetCurrentPerson() };
		        this->PlayDyingSFX(aDoor->GetCurrentPerson());
			    aDoor->ShowPersonDying();

			} else {
				//NO .. //char is HATMAN?
				if ( aDoor->GetCurrentPerson() == PERSON_HATMAN ) {
				    _arrCodes[aDoor->GetPosition()] = { aDoor->ProcessHatman(), aDoor->GetCurrentPerson() };
				    
				//else, killed an INNOCENT!
				} else {
				    _arrCodes[aDoor->GetPosition()] = { GAME_KILL_INNOCENT, aDoor->GetCurrentPerson() };
			        this->PlayDyingSFX(aDoor->GetCurrentPerson());
			        aDoor->ShowPersonDying();
				}
			}
		}
	}						
}

///returns a reference to a door, based on the hit button
//Y		: Door 1
//B,X	: Door 2
//A		: Door 3
Door* MainStage::GetDoorByPressedButton(s8 _btnY, s8 _btnX, s8 _btnB, s8 _btnA) {
	if ( _btnY > 0 ) {
		return this->myDoors[this->myCurrentDoor];
	} 
	else
		if ( _btnX > 0 || _btnB > 0 ) {
			return this->myDoors[this->myCurrentDoor+1];
		}
		else
			if ( _btnA > 0 ) {
				return this->myDoors[this->myCurrentDoor+2];
			}
}

bool MainStage::GetAllDoorsWaiting() {
	Door *aDoor = NULL;
	bool allWaiting = true;

	//do the processing on current door + 2 (doors 1,2,3 ...)
	for (u8 x = this->myCurrentDoor; x < this->myCurrentDoor + 3; x++) {
		aDoor = this->myDoors[x];
		
		//all doors need to be WAITING, to be able to scroll
		if ( aDoor->GetStatus() != DOOR_WAITING ) {
			allWaiting = false;
			break;
		}
	}
	return allWaiting;
}

void MainStage::DrawDollar(u8 _doorPosition) {
	u8 xPosition = 0;
	
	switch (_doorPosition) {
		case 0: xPosition = 10; break;
		case 1: xPosition = 26; break;
		case 2: xPosition = 42; break;
		case 3: xPosition = 58; break;
		case 4: xPosition = 74; break;
		case 5: xPosition = 90; break;
		case 6: xPosition = 154; break;
		case 7: xPosition = 170; break;
		case 8: xPosition = 186; break;
		case 9: xPosition = 201; break;
		case 10: xPosition = 217; break;
		case 11: xPosition = 233; break;
	}

	//print dollar sprite
	UIManager::ShowSprite(SP_DOLLAR + _doorPosition, xPosition, 10);
}

void MainStage::RegisterDoorMoney(u8 _doorPosition) {
	//play dollar sound
	mmEffect(SFX_MONEY);

	//print dollarSign on top of door
	this->DrawDollar(_doorPosition);

	//play big dollar animation
	UIManager::ShowSprite(SP_BIGDOLLAR, 121, 9);
	PA_StartSpriteAnimEx(0, SP_BIGDOLLAR, 0, 3, 15, ANIM_UPDOWN, 1);
}

void MainStage::DrawStage() {
	//load BG with score and information
	PA_LoadBackground(0, BG_STAGE, &bg_mainStage);
	
	//load BG with desks
	PA_LoadBackground(0, BG_STAGE_DESKS, &bg_desks);

	//load BG with doors
	PA_LoadBackground(0, BG_STAGE_DOORS, &bg_doors);

	//draw red bar
	PA_SetSpritePrio(0, SP_REDBAR, 3);
	PA_SetSpritePrio(0, SP_REDBAR+1, 3);
	UIManager::ShowSprite(SP_REDBAR, 9, 0);
	UIManager::ShowSprite(SP_REDBAR+1, 41, 0);
}

//delete all loaded backgrounds and reset sprite system
void MainStage::ClearStage() {
	PA_ResetSpriteSys(); //clear all sprites and such

	PA_ClearBg(0, BG_TEXT);
	PA_DeleteBg(0, BG_STAGE);
	PA_DeleteBg(0, BG_STAGE_DESKS);
	PA_DeleteBg(0, BG_STAGE_DOORS);
}

//reset the mainStage object:
void MainStage::ResetStage() {
	u8 x = 0;

	//clear BG graphics
	this->ClearStage();

	//release memory used by animations (for each door):
	for (x = 0; x < 3; x++) {
		AnimationManager::ReleaseMemory(TAG_PERSON + x, true);
	}

	//reset doors:
	//initialize random wait for each door:
	PA_InitRand(); //start random seed
	for (x = 0; x < 12; x++) {
		this->myDoors[x]->Reset();
		this->myDoors[x]->SetWaiting(PA_RandMinMax(1, MAX_WAIT_TIME));
	}
	
	//set current door to 0:
	this->myCurrentDoor = 0;
}

void MainStage::Scroll(s8 _direction) {
	u8 ammount = 0; u8 x = 0; u8 pos = 0; u8 doorPos = 0;
	u16 redbarOffset = 0;
	bool scrollDoors = true;


	//scroll
	while (scrollDoors) {
		if ( x < 65 ) {
			PA_BGScrollX(0, BG_STAGE_DOORS, ammount);
			sleep(0.04);
			ammount += 4 * _direction;
			x++;
		} else {
			scrollDoors = false;
		}
	}


	//calculate new starting door index
	if ( _direction == SCROLL_LEFT ) {
		//get redBar position:
		if ( this->myCurrentDoor > 0) {
			doorPos = this->myCurrentDoor - 3;
		} else {
			doorPos = 9;
		}


		//update door start index [ (0) 1 2   (3) 4 5   (6) 7 8   (9)10 11 ]
		if ( this->myCurrentDoor == 0 )
			this->myCurrentDoor = 9;
		else
			this->myCurrentDoor -= 3;

	//scroll to RIGHT
	} else {
		//get redBar position:
		if ( this->myCurrentDoor == 9) {
			doorPos = 0;
		} else {
			doorPos = this->myCurrentDoor + 3;
		}


		if ( this->myCurrentDoor == 9 )
			this->myCurrentDoor = 0;
		else
			this->myCurrentDoor += 3;
	}


	//Draw redBar - active door indicator
	redbarOffset = this->GetRedBarOffset(doorPos);
	UIManager::ShowSprite(SP_REDBAR, redbarOffset, 0);
	UIManager::ShowSprite(SP_REDBAR+1, redbarOffset+32, 0);



	//update active door's index:
	for (x=this->myCurrentDoor; x<this->myCurrentDoor+3; x++) {
		this->myDoors[x]->SetPosition(pos++);
	}

}

u16 MainStage::GetRedBarOffset(u8 _doorPosition) {
	switch(_doorPosition){
		case 0: return 9; break;
		case 3: return 58; break;
		case 6: return 152; break;
		case 9:	return 201; break;
	}
}

void MainStage::PlayDyingSFX(u8 _person) {
	switch(_person) {
		case PERSON_BANDIT1:
			mmEffect(SFX_BANDIT_DIE);
			break;
		case PERSON_MAN:
			mmEffect(SFX_MAN_DIE);
			break;
		case PERSON_WOMAN:
			break;
	}
}

bool MainStage::GetAllDoorsWithMoney() {
	bool ret = true;

	for (u8 x=0; x<12; x++) {
		if ( !this->myDoors[x]->GetMoneyFlag() ) {
			ret = false;
			break;
		}
	}

	return ret;
}

void MainStage::BlinkDollarSigns() {
	for (u8 y=0; y<8; y++ ) {
		for (u8 x=0; x<12; x++) {
			UIManager::HideSprite(SP_DOLLAR + x );
		}
		sleep(0.2);
		for (u8 x=0; x<12; x++) {
			this->DrawDollar(x);
		}
		sleep(0.2);
	}
}