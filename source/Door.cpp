/* vvvvvvvvvvvvvvvvvvvvvvvvvvv INCLUDES vvvvvvvvvvvvvvvvvvvvvvvvvvvvvv */
#include "Door.h"

/* ^^^^^^^^^^^^^^^^^^^^^^^^^^^ INCLUDES ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^ */


/* vvvvvvvvvvvvvvvvvvvv CONSTRUCTOR/DESTRUCTOR vvvvvvvvvvvvvvvvvvvvvvv */
Door::Door(u8 _id) {
	this->myID = _id;

	this->myPersonAlive = true;
	this->mySpeed = 7;
	this->myStatus = DOOR_WAITING;
	this->myBonus = false;
	this->myMoneyFlag = false;
}

Door::~Door(void) {
}
/* ^^^^^^^^^^^^^^^^^^^^ CONSTRUCTOR/DESTRUCTOR ^^^^^^^^^^^^^^^^^^^^^^^ */


/* vvvvvvvvvvvvvvvvvvvvvvvvvvv SETTERS vvvvvvvvvvvvvvvvvvvvvvvvvvvvvv */
void Door::SetWaiting(u8 _amount) {
	this->myWaitingAmount = _amount * 60;
	this->myStatus = DOOR_WAITING;
}

void Door::SetPosition(u8 _pos) {
	this->myPosition = _pos;
}

void Door::SetSpeed(u8 _fps) {
	this->mySpeed = _fps;
}

void Door::SetMoneyFlag(bool _flag) {
	this->myMoneyFlag = _flag;
}
/* ^^^^^^^^^^^^^^^^^^^^^^^^^^^ SETTERS ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^ */


/* vvvvvvvvvvvvvvvvvvvvvvvvvvv GETTERS vvvvvvvvvvvvvvvvvvvvvvvvvvvvvv */
u8 Door::GetStatus() {
	return this->myStatus;
}

u8 Door::GetOpenCounter() {
	return this->myOpenAmount;
}

u8 Door::GetPosition() {
	return this->myPosition;
}

u8 Door::GetID() {
	return this->myID;
}

bool Door::GetMoneyFlag() {
	return this->myMoneyFlag;
}
/* ^^^^^^^^^^^^^^^^^^^^^^^^^^^ GETTERS ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^ */


/* vvvvvvvvvvvvvvvvvvvvvvvvvvv METHODS vvvvvvvvvvvvvvvvvvvvvvvvvvvvvv */
void Door::DecWaiting(u8 _amount) {
	if ( this->myWaitingAmount > 0 )
		this->myWaitingAmount--;
	else
		this->myStatus = DOOR_CLOSED;
}

void Door::DecOpen(u8 _amount) {
	if ( this->myOpenAmount > 0 )
		this->myOpenAmount--;
}

void Door::Open() {
	//get configuration object for person at current level:
	ConfigPerson* cfgPerson = ::levelManager.GetConfigPerson();

	this->myOpenAmount = cfgPerson->GetDoorOpenAmmount();

	//display person behind the door
	this->ShowPerson(cfgPerson);

	//show the Open door sprites:
	this->myOpenSpriteID = UIManager::PlayOpenDoorAnim(this->myPosition);

	//just changed the status:
	this->myStatus = DOOR_OPENING;
}

void Door::Close() {
	//show the close door sprites and start animation:
	this->myCloseSpriteID = UIManager::PlayCloseDoorAnim(this->myPosition);

	//just changed the status:
	this->myStatus = DOOR_CLOSING;
}

void Door::ShowPerson(ConfigPerson *_cfgPerson) {
	this->myPersonAlive = true;
	this->myCurrentPerson = _cfgPerson->GetCode();
    
    //if person is HATMAN, call specific method to display animation on 1st frame:
    if ( _cfgPerson->GetCode() == PERSON_HATMAN ) {
        this->myHatmanSpriteID = UIManager::LoadHatmanAnim(this->myPosition);
    }

	//draw person
	UIManager::DrawPerson(_cfgPerson->GetCode(), this->myPosition);
}

//Update door counter variables and/or status flag
void Door::UpdateStatus() {

	switch(this->myStatus) {
		case DOOR_WAITING: 
			//decrease waiting counter. It will change to CLOSE when counter reaches zero
			this->DecWaiting(1); 
			break;

		case DOOR_OPENING: 
			//only frame 3 is relevant if door is opening (to check if has fully opened)
			if ( PA_GetSpriteAnimFrame(0, this->myOpenSpriteID.arrSpriteID[0]) == 3 ) {
				this->myStatus = DOOR_OPEN;
			}
			break;

		case DOOR_OPEN: 
			this->DecOpen(1); 
			break;

		case DOOR_CLOSING:
			//only frame 3 is relevant if door is closing (to check if has fully closed)
			if ( PA_GetSpriteAnimFrame(0, this->myCloseSpriteID.arrSpriteID[0]) == 3 ) {
				//just become closed
				this->myStatus = DOOR_JUST_CLOSED;
			}
			break;

		case DOOR_JUST_CLOSED:
			UIManager::ResetDoorGraphics(this->myCurrentPerson, this->myPosition);

			//set that there's no longer a person on door
			this->myCurrentPerson = PERSON_NONE;
			this->myBonus = false;

			//set waiting time and status
			this->SetWaiting(PA_RandMinMax(MIN_WAIT_TIME, MAX_WAIT_TIME));
			break;
	}
}

u8 Door::GetCurrentPerson() {
	return this->myCurrentPerson;
}

bool Door::IsPersonBandit() {
	return ( this->myCurrentPerson == PERSON_BANDIT1 );
}

bool Door::IsPersonCustomer() {
	return ( this->myCurrentPerson != PERSON_BANDIT1 && this->myCurrentPerson != PERSON_HATMAN );
}

bool Door::IsPersonAlive() {
	return this->myPersonAlive;
}

//reset door status, etc
void Door::Reset() {
	this->myStatus = DOOR_WAITING;
	this->myMoneyFlag = false;
}

void Door::ShowPersonDying() {
	UIManager::PlayPersonDyingAnim(this->myCurrentPerson, this->myPosition);
	this->myPersonAlive = false;
}

u8 Door::ProcessHatman() {
    u8 currFrame = PA_GetSpriteAnimFrame(0, this->myHatmanSpriteID.arrSpriteID[0]);
	currFrame++;

    //has hat left? (is in animation frame num. < 6?
    if ( currFrame < 6 ) {
	    //YES.. //advance hat animation frame
	    PA_SetSpriteAnimFrame(0, this->myHatmanSpriteID.arrSpriteID[0], currFrame);
	    return GAME_KILL_HAT;
	}

	//NO .. (randomize bomb/money, go to corresponding animation frame - draw)
	if ( currFrame == 6 ) {
		bool drawBomb = PA_RandMinMax(0, 1) > 0;

		if ( drawBomb ) {
			PA_SetSpriteAnimFrame(0, this->myHatmanSpriteID.arrSpriteID[0], currFrame+1);
		} else {
			PA_SetSpriteAnimFrame(0, this->myHatmanSpriteID.arrSpriteID[0], currFrame+2);
		}
	}
	
	else {
	    //hit a BOMB? 
		if ( currFrame == 8 ) {
		    //YES .. return KILL_BOMB
			return GAME_KILL_BOMB;
		} 
		else 
		    if ( !this->myBonus ) {
			    //NO .. return KILL_MONEY
			    this->myBonus = true;
			    PA_SetSpriteAnimFrame(0, this->myHatmanSpriteID.arrSpriteID[0], currFrame);
			    return GAME_KILL_MONEY;
    		}
	}
    
    return GAME_CODE_NULL;
}
/* ^^^^^^^^^^^^^^^^^^^^^^^^^^^ METHODS ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^ */