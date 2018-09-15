/* vvvvvvvvvvvvvvvvvvvvvvvvvvv INCLUDES vvvvvvvvvvvvvvvvvvvvvvvvvvvvvv */
#pragma once

#include "AnimationManager.h"
#include "TextManager.h"
#include "LevelManager.h"
#include "UIManager.h"
#include "MainStage.h"
#include "DuelStage.h"
#include "constants.h"
#include "utils.h"

/* vvvvvvvvv MAXMOD vvvvvvvvvv */
#include <maxmod9.h>
// Include the soundbank
#include "soundbank_bin.h"
#include "soundbank.h"
/* ^^^^^^^^^ MAXMOD ^^^^^^^^^^ */
/* ^^^^^^^^^^^^^^^^^^^^^^^^^^^ INCLUDES ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^ */

extern Animations arrAnimations[10]; //to control loaded animations
extern LevelManager levelManager;

class Game {

	private:
		//simple variables
		u8 myGameLevel;
		u8 myLives;
		u32 myScore;
		
		MainStage *myMainStage;
		TextManager *myTextManager;

		void ProcessReturningCodes(ReturnCode _arrReturnCodes[]); //update total score with points earned from a call to 'ProcessDoors'
		void PrintLifes();
		void PrintScore();
		void PlayLevelMusic(u8 _level);
		void StopLevelMusic(u8 _level);
		
		bool GetPlayerLostLife(ReturnCode _arrReturnCodes[]);
		bool GetPlayerAdvancedLevel(ReturnCode _arrReturnCodes[]);

		void CheckAnimations(); //will check if loaded animations have reached the last frame. If so, delete 
	public:
		Game(void);
		~Game();

		//start the game on a certain level
		u8 Run(u8 _level);
		bool RunDuelStage(u8 _level); //runs the duel stage for the current level
		void ShowPhaseScreen(u8 _level);
};
