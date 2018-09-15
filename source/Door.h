#pragma once

#include <PA9.h>

#include "constants.h"
#include "utils.h"
#include "UIManager.h"
#include "LevelManager.h"
#include "ConfigPerson.h"


#define MAX_WAIT_TIME	7 //change: this value will come from the 'LevelConfig' object.
#define MIN_WAIT_TIME	3 //change: this value will come from the 'LevelConfig' object.


extern LevelManager levelManager;

class Door {

	private:
		//PROPERTIES
		u8 myID;
		//properties to set IDs to animation sprites:
		SpriteIDs myOpenSpriteID; //to keep track of open animation
		SpriteIDs myCloseSpriteID; //to keep track of close animation
		SpriteIDs myHatmanSpriteID; //to keep track of HATMAN animation

		u8 myScrollSize; //amount of pixels this door takes to do a side-scroll
		u32 myWaitingAmount; //amount of time door stays closed, waiting to be opened
		u32 myOpenAmount; //amount of time door stays opened
		u8 myPosition; //if door is "1st, 2nd or 3rd" door on screen
		u8 mySpeed; //speed of door animation (frames per second)
		u8 myStatus;

		u8 myCurrentPerson; //keep track of current person
		bool myPersonAlive;
		bool myMoneyFlag;
		bool myBonus;

		//METHODS
		void ShowPerson(ConfigPerson *cfgPerson); //display the Person image behind the door (randomize one character)
	public:
		Door(u8 _id);
		~Door(void);

		void SetWaiting(u8 _amount); //set door to be on WAITING for an amount of time
		void SetPosition(u8 _pos);
		void SetSpeed(u8 _fps);
		void SetMoneyFlag(bool _flag);

		void DecWaiting(u8 _amount); //decrease waiting counter
		void DecOpen(u8 _amount); //decrease open counter
		void UpdateStatus(); //update it's status based on animation frame or waiting time. Must be called once per VBL.

		u8 GetStatus();
		u8 GetOpenCounter();
		u8 GetPosition();
		u8 GetID();
		u8 GetCurrentPerson(); //return the PERSON_ code for current person behind the door
		u8 ProcessHatman(); //get return code for a hit in a Hatman (KILL_BOMB, KILL_MONEY, KILL_HAT)
		bool GetMoneyFlag();

		bool IsPersonBandit(); //return true if person behind door is a bandit (indepent of current game level)
		bool IsPersonCustomer(); //return true if person behind door is a bandit (indepent of current game level)
		bool IsPersonAlive(); //return true if person behind door is alive

		void Open(); //start the open door animation
		void Close(); //start the close door animation

		void Reset();

		void ShowPersonDying();
};
