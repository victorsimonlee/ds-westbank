/* vvvvvvvvvvvvvvvvvvvvvvvvvvv INCLUDES vvvvvvvvvvvvvvvvvvvvvvvvvvv */
#include <PA9.h>
/* vvvvvvvvv MAXMOD vvvvvvvvvv */
#include <maxmod9.h>
// Include the soundbank
#include "soundbank_bin.h"
#include "soundbank.h"
/* ^^^^^^^^^ MAXMOD ^^^^^^^^^^ */

//include game classes
#include "Game.h"
#include "UIManager.h"

//general purpose includes
#include "utils.h"
#include "utils.c"
#include "constants.h"
#include "types.h"

//includes for graphics
#include "all_gfx.h"
/* ^^^^^^^^^^^^^^^^^^^^^^^^^^^ INCLUDES ^^^^^^^^^^^^^^^^^^^^^^^^^^^ */

/* vvvvvvvvvvvvvvvvvvvvvvvvvvv GLOBAL VARIABLES vvvvvvvvvvvvvvvvvvvvvvvvvvv */
Animations arrAnimations[10];
LevelManager levelManager;
/* ^^^^^^^^^^^^^^^^^^^^^^^^^^^ GLOBAL VARIABLES ^^^^^^^^^^^^^^^^^^^^^^^^^^^ */

/* vvvvvvvvvvvvvvvvvv MAIN FUNCTIONS HEADERS vvvvvvvvvvvvvvvvvvvvvv */
void showCredits();			// Show game credits
void showHiscores();		// Show Hi-Scores table
u8 showMenu();				// Show Game Options Menu
/* ^^^^^^^^^^^^^^^^^^^ MAIN FUNCTIONS HEADERS ^^^^^^^^^^^^^^^^^^^^^ */


/* vvvvvvvvvvvvvvvvvvvvvvvvv MAIN LOOP vvvvvvvvvvvvvvvvvvvvvvvvvvvv */
int main() {
	PA_Init();    // Initializes PA_Lib
	PA_InitVBL(); // Initializes a standard VBL

	
	//init MemoryManagement array (for animations)
	for (u8 x=0; x<10; x++) {
		arrAnimations[x].id = -1;
		arrAnimations[x].lastFrame = 0;
	}

	// Initialize Maxmod
	mmInitDefaultMem((mm_addr)soundbank_bin);

	//main loop should start with: 
	//u8 mainLoopStatus = MAIN_LOOP_SPLASH;
	u8 mainLoopStatus = MAIN_LOOP_MENU;

	//main game loop:
	while(1) {
		switch(mainLoopStatus) {
			case MAIN_LOOP_SPLASH:
				//write 'To Pedro':
				UIManager::WriteConsiderations();

				UIManager::DrawSplashScreens();
				mainLoopStatus = MAIN_LOOP_INTRO;
			break;

			case MAIN_LOOP_INTRO:
				UIManager::DrawIntroductionAnimation();
				mainLoopStatus = MAIN_LOOP_MENU;
			break;

			case MAIN_LOOP_MENU:
				mainLoopStatus = showMenu();
			break;

			case MAIN_LOOP_CREDITS:
				showCredits();
				mainLoopStatus = MAIN_LOOP_MENU;
			break;

			case MAIN_LOOP_HISCORES:
				showHiscores();
				mainLoopStatus = MAIN_LOOP_MENU;
			break;

			case MAIN_LOOP_ENTERNAME:

				mainLoopStatus = MAIN_LOOP_MENU;
			break;

			case MAIN_LOOP_GAME:
				//start a new Game object and run it:
				Game* myGame = new Game();
				mainLoopStatus = myGame->Run(0);

				delete myGame;
			break;
		}
	}

	return 0;
}
/* ^^^^^^^^^^^^^^^^^^^^^^^^^^^ MAIN LOOP ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^ */



/* vvvvvvvvvvvvvvvvvv MAIN FUNCTIONS DEFINITION vvvvvvvvvvvvvvvvvvvvvvv */
void showCredits() {
}

void showHiscores() {
}

u8 showMenu() {
	s8 retCode = -1;
	u8 menuPosition = 0;

	//call static UIManager to load all game sprites at once!
	UIManager::LoadSprites(0);  //0 = will not load any level-specific graphic

	//load background image with menu options
	PA_LoadBackground(0, BG_MAIN_MENU, &bg_mainMenu);

	//load & play menu music in LOOP
	mmLoad(MOD_MENU);
	mmStart(MOD_MENU, MM_PLAY_LOOP);

	//display first option as selected
	UIManager::DrawMenuOption(MENU_START_GAME);
	
	//wait for user to choose a menu option
	while (retCode < 0) {
		
		//move gun up 
		if ( Pad.Newpress.Up ) {
			if ( menuPosition > 0 ) menuPosition--;
		}

		//move gun down
		if ( Pad.Newpress.Down ) {
			if ( menuPosition < 2 ) menuPosition++;
		}

		//select menu option
		if ( Pad.Newpress.A ) {
			//stop the music (unload it) and then send to desired game state:
			mmStop();
			mmUnload(MOD_MENU);

			//remove Bg, sprites and wait 2 sec on black screen
			PA_ResetSpriteSys();
			PA_DeleteBg(0, BG_MAIN_MENU);
			sleep(2);

			//send player to desired destination!
			switch(menuPosition) {
				case 0: retCode = MAIN_LOOP_GAME; break;
				case 1: retCode = MAIN_LOOP_HISCORES; break;
				case 2: retCode = MAIN_LOOP_CREDITS; break;
			}
		}

		//draw menu sprite
		UIManager::DrawMenuOption(menuPosition);

		PA_WaitForVBL();
	}

	PA_ResetSpriteSys(); //clear all sprites and such
	return retCode;
}
/* ^^^^^^^^^^^^^^^^^^^ MAIN FUNCTIONS DEFINITION ^^^^^^^^^^^^^^^^^^^^^^ */