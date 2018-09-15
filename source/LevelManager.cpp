/* vvvvvvvvvvvvvvvvvvvvvvvvvvv INCLUDES vvvvvvvvvvvvvvvvvvvvvvvvvvvvvv */
#include "utils.h"
#include "constants.h"
#include "LevelManager.h"
/* ^^^^^^^^^^^^^^^^^^^^^^^^^^^ INCLUDES ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^ */


LevelManager::LevelManager(void) {

}

LevelManager::~LevelManager(void) {

}

//return points earned after ProcessDoors/ProcesUserInput flow
u8 LevelManager::GetScoreFor(u8 _gameCode, u8 _personCode) {
	switch (this->myCurrentLevel) {

		//LEVEL 1
		case 1:
			switch(_gameCode) {
				//door closed with a customer behind it - making money:
				case GAME_MONEY:
					switch(_personCode) {
						case PERSON_MAN:
							return SCORE_LEVEL1_MAN;
						
						case PERSON_WOMAN:
							return SCORE_LEVEL1_WOMAN;
					}
					break;

				//player got hit:
				case GAME_BANG:
					break;

				case GAME_KILL_INNOCENT:
					break;

				case GAME_KILL_BANDIT:
					switch(_personCode) {
						case PERSON_BANDIT1:
						return SCORE_LEVEL1_BANDIT1;
					}
					break;

				case GAME_KILL_HAT:
					return SCORE_LEVEL1_HATMAN_HAT;
					break;

				case GAME_KILL_MONEY:
					return SCORE_LEVEL1_HATMAN_MONEY;
					break;
			}
			break;


		default:
			return 0;
	}
}



void LevelManager::SetCurrentLevel(u8 _level) {
	this->myCurrentLevel = _level;
}

ConfigPerson* LevelManager::GetConfigPerson() {
	ConfigPerson *cfg = new ConfigPerson();

	//randomize a number between 0 and 100
	u8 randNumber = PA_RandMinMax(0, 100);

	switch(this->myCurrentLevel) {
		//  probabilities for level 1:
		case 1:
			//00-29: MAN1		(30%)
			if ( randNumber < 30 ) {
				cfg->SetCode(PERSON_MAN);
				cfg->SetDoorOpenAmmount(120);

			//30-59: BANDIT1	(30%)
			} else if ( randNumber < 60 ) {
				cfg->SetCode(PERSON_BANDIT1);
				cfg->SetDoorOpenAmmount(60);

			//60-79: WOMAN1	(20%)
			} else if ( randNumber < 80 ) {
				cfg->SetCode(PERSON_WOMAN);
				cfg->SetDoorOpenAmmount(120);

			//80-100: HATMAN	(20%)
			} else if ( randNumber <= 100 ) {
				cfg->SetCode(PERSON_HATMAN);
				cfg->SetDoorOpenAmmount(160);
			}
			break;
	}

	return cfg;
}