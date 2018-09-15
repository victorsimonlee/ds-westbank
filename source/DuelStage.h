#pragma once

#include "Types.h"
#include "constants.h"
#include "utils.h"
#include "TextManager.h"
#include "UIManager.h"


class DuelStage {

private:
	TextManager *myTextManager;
	u8 aliveBandits; //how many bandits are alive?


	void DrawStage();
	void ClearStage(); //reset sprite system and clear BG
	void PrintCountDown();
	void DrawBanditWithdrawal(u8 _banditPos); //draw the bandit withdrawing his gun (banditId: 0, 1, 2)
	void DrawBanditDying(u8 _banditPos, bool _withdrawedGun); //draw the bandit dying and play sound (banditId: 0, 1, 2)
	void UpdateBanditActiveCounter(DuelBanditStatus *_banditStatus);
	void ProcessPlayerInput(DuelBanditStatus* _banditStatus, ReturnCode* _code);
	DuelBanditStatus GetBanditStatusInstance();

public:
	DuelStage(void);
	~DuelStage(void);

	void RunDuel(ReturnCode* _arrCodes); //starts the duel. Process player input, return input to game (caller) class.
};