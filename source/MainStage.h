#pragma once

#include <PA9.h>
#include "Types.h"
#include "constants.h"
#include "utils.h"
#include "UIManager.h"
#include "Door.h"


class MainStage {

	private:
		//PROPERTIES
		Door *myDoors[12]; //main stage contains 12 doors
		u8 myCurrentDoor; //which door is currently active (the left-most door)
		
		//METHODS
		void DrawDollar(u8 _doorPosition);
		void RegisterDoorMoney(u8 _doorPosition); //prints the dollar sign for desired door
		void ClearStage();
		u16 GetRedBarOffset(u8 _doorPosition);
		void PlayDyingSFX(u8 _person);

	public:
		void ProcessDoors(ReturnCode* _arrCodes);
		void ProcessPlayerInput(ReturnCode* _arrCodes);
		void DrawStage();
		void ResetStage();
		void PlayLostLifeAnim();
		void Scroll(s8 _direction); //scroll BG
		void BlinkDollarSigns();

		bool GetAllDoorsWaiting();
		bool GetAllDoorsWithMoney();
		Door* GetDoorByPressedButton(s8 _btnY, s8 _btnX, s8 _btnB, s8 _btnA);

		ReturnCode GetReturningCode(u8 _doorPosition); //return the returning code for the required door position.

		MainStage();
		~MainStage(void);

};
