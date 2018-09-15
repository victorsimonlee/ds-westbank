/**************************************************************************************************************************
*   THIS FILE DEFINES TYPES WHICH ARE USED ACROSS THE ENTIRE GAME														  *
***************************************************************************************************************************/
#pragma once
#include <PA9.h>


/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//	ReturnCode																										   //
//---------------------------------------------------------------------------------------------------------------------//
// Used to return a 'game code' and a person in which that code affects.											   //
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
typedef struct stReturnCode ReturnCode;
struct stReturnCode {
	s8 code; //Game code: values defined in Constants.h
	s8 person; //Person code: values defined in Constants.h
};

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//	SpriteIDs																										   //
//---------------------------------------------------------------------------------------------------------------------//
// Used to store a set of sprite IDs: we may not know how many IDs a sprite may be composed of.						   //
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
typedef struct stSpriteID SpriteIDs;
struct stSpriteID {
	u8 arrSpriteID[20];
	u8 numberOfIds; //how many IDs this sprite uses?
};

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//	ANIMATIONS																										   //
//---------------------------------------------------------------------------------------------------------------------//
// Used to control animations. main game loop frequently checks if animations have reached its last frame.			   //
// If so, it deletes the loaded GFx.																				   //
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
typedef struct stAnimations Animations;
struct stAnimations {
	s8 id; //animation sprite Id
	u8 lastFrame; //if reached this last frame number, will be deleted
	u8 tag; //used to indicate which 'category' this animation belongs to
};

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//	DuelBanditAction																								   //
//---------------------------------------------------------------------------------------------------------------------//
// Holds information about the action a Bandit will take when duel countdown hits zero.								   //
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
typedef struct stDuelBanditStatus DuelBanditStatus;
struct stDuelBanditStatus {
	bool readyToWithdraw;
	bool withdrawed;
	bool readyToShoot;
	bool shoot;
	bool alive;
	
	u8 timeoutDrawGun;
	u8 timeoutShootGun;
};
