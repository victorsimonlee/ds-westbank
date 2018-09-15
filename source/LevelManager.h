/*******************************************************************
*   THIS CLASS MAKES CALCULATIONS BASED ON CURRENT GAME LEVEL.     *
*   AN INSTANCE OF IT IS USED BY ALMOST ALL OTHER CLASS INSTANCES. *
********************************************************************/
#pragma once
#include <PA9.h>
#include "ConfigPerson.h"



class LevelManager {

private:
	u8 myCurrentLevel;

public:
	LevelManager(void);
	~LevelManager(void);

	///////////////////// GAME-RELATED CONFIGURATION ////////////////////////
	void SetCurrentLevel(u8 _level); //sets the active level number (default: 1)
	u8 GetScoreFor(u8 _gameCode, u8 _personCode); //return points earned after ProcessDoors/ProcesUserInput flow.
	/////////////////////////////////////////////////////////////////////////


	///////////////////// PERSON-RELATED CONFIGURATION ////////////////////////
	ConfigPerson* GetConfigPerson(); //returns a object with configuration settings for a Person
	/////////////////////////////////////////////////////////////////////////
	
};