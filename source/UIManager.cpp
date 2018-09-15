/* vvvvvvvvvvvvvvvvvvvvvvvvvvv INCLUDES vvvvvvvvvvvvvvvvvvvvvvvvvvv */
#include "UIManager.h"


//splash screens
#include "bg_Splash_developedBy_1.h"
#include "bg_Splash_developedBy_2.h"
#include "bg_palib_1.h"
#include "bg_palib_2.h"
/* ^^^^^^^^^^^^^^^^^^^^^^^^^^^ INCLUDES ^^^^^^^^^^^^^^^^^^^^^^^^^^^ */

UIManager::UIManager(void) {
}

UIManager::~UIManager(void) {
}

void UIManager::LoadSprites(s8 _level) {
	//unload all loaded sprite data
	PA_ResetSpriteSys();

	/* vvvvvvvvvvvvvvvvvvvvvvvvvvv GAME-WIDE SPRITES vvvvvvvvvvvvvvvvvvvvvvvvvvv */
	//load life sprite
	PA_LoadSpritePal(0, LIFE_PAL, (void*)sp_life_Pal);
	u16 GfxLife = PA_CreateGfx(0, (void*)sp_life_Sprite, OBJ_SIZE_16X32, 1);
	PA_CreateSpriteFromGfx(0, SP_LIFE, GfxLife, OBJ_SIZE_16X32, 1, LIFE_PAL, -64, -64);
	PA_CreateSpriteFromGfx(0, SP_LIFE+1, GfxLife, OBJ_SIZE_16X32, 1, LIFE_PAL, -64, -64);
	PA_CreateSpriteFromGfx(0, SP_LIFE+2, GfxLife, OBJ_SIZE_16X32, 1, LIFE_PAL, -64, -64);
	PA_CreateSpriteFromGfx(0, SP_LIFE+3, GfxLife, OBJ_SIZE_16X32, 1, LIFE_PAL, -64, -64);

	if (_level >= 0) {
		//HATMAN PALLETE
		PA_LoadSpritePal(0, CHAR_HATMAN_PAL, (void*)sp_hatman_Pal);
	    
		//OPEN door anim: loads 3 of each sprites. One per door
		PA_LoadSpritePal(0, DOOR_PAL, (void*)sp_doors_Pal);
		//door pos 0
		PA_CreateSprite(0, SP_DOOR_OPEN, (void*)sp_doorsOpen_top_Sprite, OBJ_SIZE_64X64, 1, DOOR_PAL, -64, -64);
		PA_CreateSprite(0, SP_DOOR_OPEN+1, (void*)sp_doorsOpen_bot_Sprite, OBJ_SIZE_64X64, 1, DOOR_PAL, -64, -64);
		//door pos 1
		PA_CreateSprite(0, SP_DOOR_OPEN+2, (void*)sp_doorsOpen_top_Sprite, OBJ_SIZE_64X64, 1, DOOR_PAL, -64, -64);
		PA_CreateSprite(0, SP_DOOR_OPEN+3, (void*)sp_doorsOpen_bot_Sprite, OBJ_SIZE_64X64, 1, DOOR_PAL, -64, -64);
		//door pos 2
		PA_CreateSprite(0, SP_DOOR_OPEN+4, (void*)sp_doorsOpen_top_Sprite, OBJ_SIZE_64X64, 1, DOOR_PAL, -64, -64);
		PA_CreateSprite(0, SP_DOOR_OPEN+5, (void*)sp_doorsOpen_bot_Sprite, OBJ_SIZE_64X64, 1, DOOR_PAL, -64, -64);

		//CLOSE door anim: loads 3 of each sprites. One per door
		//door pos 0
		PA_CreateSprite(0, SP_DOOR_CLOSE, (void*)sp_doorsClose_top_Sprite, OBJ_SIZE_64X64, 1, DOOR_PAL, -64, -64);
		PA_CreateSprite(0, SP_DOOR_CLOSE+1, (void*)sp_doorsClose_bot_Sprite, OBJ_SIZE_64X64, 1, DOOR_PAL, -64, -64);
		//door pos 1
		PA_CreateSprite(0, SP_DOOR_CLOSE+2, (void*)sp_doorsClose_top_Sprite, OBJ_SIZE_64X64, 1, DOOR_PAL, -64, -64);
		PA_CreateSprite(0, SP_DOOR_CLOSE+3, (void*)sp_doorsClose_bot_Sprite, OBJ_SIZE_64X64, 1, DOOR_PAL, -64, -64);
		//door pos 2
		PA_CreateSprite(0, SP_DOOR_CLOSE+4, (void*)sp_doorsClose_top_Sprite, OBJ_SIZE_64X64, 1, DOOR_PAL, -64, -64);
		PA_CreateSprite(0, SP_DOOR_CLOSE+5, (void*)sp_doorsClose_bot_Sprite, OBJ_SIZE_64X64, 1, DOOR_PAL, -64, -64);

		//load DOLLAR SIGN sprites (one dollar sign for each door):
		PA_LoadSpritePal(0, DOLLAR_PAL, (void*)sp_dollar_Pal);
		u16 GfxDolar = PA_CreateGfx(0, (void*)sp_dolar_Sprite, OBJ_SIZE_16X16, 1);
		PA_CreateSpriteFromGfx(0, SP_DOLLAR, GfxDolar, OBJ_SIZE_16X16, 1, DOLLAR_PAL, -64, -64);
		PA_CreateSpriteFromGfx(0, SP_DOLLAR+1, GfxDolar, OBJ_SIZE_16X16, 1, DOLLAR_PAL, -64, -64);
		PA_CreateSpriteFromGfx(0, SP_DOLLAR+2, GfxDolar, OBJ_SIZE_16X16, 1, DOLLAR_PAL, -64, -64);
		PA_CreateSpriteFromGfx(0, SP_DOLLAR+3, GfxDolar, OBJ_SIZE_16X16, 1, DOLLAR_PAL, -64, -64);
		PA_CreateSpriteFromGfx(0, SP_DOLLAR+4, GfxDolar, OBJ_SIZE_16X16, 1, DOLLAR_PAL, -64, -64);
		PA_CreateSpriteFromGfx(0, SP_DOLLAR+5, GfxDolar, OBJ_SIZE_16X16, 1, DOLLAR_PAL, -64, -64);
		PA_CreateSpriteFromGfx(0, SP_DOLLAR+6, GfxDolar, OBJ_SIZE_16X16, 1, DOLLAR_PAL, -64, -64);
		PA_CreateSpriteFromGfx(0, SP_DOLLAR+7, GfxDolar, OBJ_SIZE_16X16, 1, DOLLAR_PAL, -64, -64);
		PA_CreateSpriteFromGfx(0, SP_DOLLAR+8, GfxDolar, OBJ_SIZE_16X16, 1, DOLLAR_PAL, -64, -64);
		PA_CreateSpriteFromGfx(0, SP_DOLLAR+9, GfxDolar, OBJ_SIZE_16X16, 1, DOLLAR_PAL, -64, -64);
		PA_CreateSpriteFromGfx(0, SP_DOLLAR+10, GfxDolar, OBJ_SIZE_16X16, 1, DOLLAR_PAL, -64, -64);
		PA_CreateSpriteFromGfx(0, SP_DOLLAR+11, GfxDolar, OBJ_SIZE_16X16, 1, DOLLAR_PAL, -64, -64);

		//load big dollar animation
		PA_LoadSpritePal(0, BIGDOLLAR_PAL, (void*)sp_BigDollar_Pal);
		PA_CreateSprite(0, SP_BIGDOLLAR, (void*)sp_BigDollar_Sprite, OBJ_SIZE_16X16, 1, BIGDOLLAR_PAL, -64, -64);


		//load player shoot sprite (uses the same pallete as doors)
		PA_CreateSprite(0, SP_SHOOT, (void*)sp_shoot_Sprite, OBJ_SIZE_8X8, 1, DOOR_PAL, -64, -64);
		PA_CreateSprite(0, SP_SHOOT+1, (void*)sp_shoot_Sprite, OBJ_SIZE_8X8, 1, DOOR_PAL, -64, -64);
		PA_CreateSprite(0, SP_SHOOT+2, (void*)sp_shoot_Sprite, OBJ_SIZE_8X8, 1, DOOR_PAL, -64, -64);

		
		//red bar - active doors indicator
		PA_LoadSpritePal(0, REDBAR_PAL, (void*)sp_redBar_Pal);
		PA_CreateSprite(0, SP_REDBAR, (void*)sp_redBar_1_Sprite, OBJ_SIZE_32X8, 1, REDBAR_PAL, -64, -64);
		PA_CreateSprite(0, SP_REDBAR+1, (void*)sp_redBar_2_Sprite, OBJ_SIZE_16X8, 1, REDBAR_PAL, -64, -64);
	}
	/* ^^^^^^^^^^^^^^^^^^^^^^^^^^^ GAME-WIDE SPRITES ^^^^^^^^^^^^^^^^^^^^^^^^^^^ */


	/* vvvvvvvvvvvvvvvvvvvvvvvvvvv RELATED TO LEVEL 0 (NOT IN-GAME) vvvvvvvvvvvvvvvvvvvvvvvvvvv */
	if ( _level == LEVEL_NOT_IN_GAME ) {
		//MENU SPRITES (menu options)
		//start game
		PA_LoadSpritePal(0, PAL_MENU, (void*)sp_menuStart_Pal);
		PA_CreateSprite(0, SP_MENU_START1, (void*)sp_menu_start_1_Sprite, OBJ_SIZE_32X16, 1, PAL_MENU, -64, -64);
		PA_CreateSprite(0, SP_MENU_START2, (void*)sp_menu_start_2_Sprite, OBJ_SIZE_32X16, 1, PAL_MENU, -64, -64);
		PA_CreateSprite(0, SP_MENU_START3, (void*)sp_menu_start_3_Sprite, OBJ_SIZE_32X16, 1, PAL_MENU, -64, -64);
		//hiscores
		PA_CreateSprite(0, SP_MENU_HISCORES1, (void*)sp_menu_hiscores_1_Sprite, OBJ_SIZE_32X16, 1, PAL_MENU, -64, -64);
		PA_CreateSprite(0, SP_MENU_HISCORES2, (void*)sp_menu_hiscores_2_Sprite, OBJ_SIZE_32X16, 1, PAL_MENU, -64, -64);
		PA_CreateSprite(0, SP_MENU_HISCORES3, (void*)sp_menu_hiscores_3_Sprite, OBJ_SIZE_8X16, 1, PAL_MENU, -64, -64);
		//credits
		PA_CreateSprite(0, SP_MENU_CREDITS1, (void*)sp_menu_credits_1_Sprite, OBJ_SIZE_32X16, 1, PAL_MENU, -64, -64);
		PA_CreateSprite(0, SP_MENU_CREDITS2, (void*)sp_menu_credits_2_Sprite, OBJ_SIZE_32X16, 1, PAL_MENU, -64, -64);
	}
	/* ^^^^^^^^^^^^^^^^^^^^^^^^^^^ RELATED TO LEVEL 0 (NOT IN-GAME) ^^^^^^^^^^^^^^^^^^^^^^^^^^^ */

	
	/* vvvvvvvvvvvvvvvvvvvvvvvvvvv RELATED TO LEVEL 1 vvvvvvvvvvvvvvvvvvvvvvvvvvv */
	if ( _level >= 1 ) {
		//////////////////////////////// LOAD MAN: /////////////////////////////////////////////////////////////////////////////
		//pallete
		PA_LoadSpritePal(0, CHAR_MAN_PAL, (void*)sp_man_Pal);
		PA_LoadSpritePal(0, CHAR_MAN_DIE_PAL, (void*)sp_man_die_Pal);

		//gfx for top/bot sprites
		u16 GfxMan1_top = PA_CreateGfx(0, (void*)sp_man_1a_Sprite, OBJ_SIZE_64X64, 1);
		u16 GfxMan1_bot = PA_CreateGfx(0, (void*)sp_man_1b_Sprite, OBJ_SIZE_64X64, 1);

		//man1 pos 0
		PA_CreateSpriteFromGfx(0, SP_CHAR_MAN, GfxMan1_top, OBJ_SIZE_64X64, 1, CHAR_MAN_PAL, -64, -64);
		PA_CreateSpriteFromGfx(0, SP_CHAR_MAN+1, GfxMan1_bot, OBJ_SIZE_64X64, 1, CHAR_MAN_PAL, -64, -64);
		//man1 pos 1
		PA_CreateSpriteFromGfx(0, SP_CHAR_MAN+2, GfxMan1_top, OBJ_SIZE_64X64, 1, CHAR_MAN_PAL, -64, -64);
		PA_CreateSpriteFromGfx(0, SP_CHAR_MAN+3, GfxMan1_bot, OBJ_SIZE_64X64, 1, CHAR_MAN_PAL, -64, -64);
		//man1 pos 2
		PA_CreateSpriteFromGfx(0, SP_CHAR_MAN+4, GfxMan1_top, OBJ_SIZE_64X64, 1, CHAR_MAN_PAL, -64, -64);
		PA_CreateSpriteFromGfx(0, SP_CHAR_MAN+5, GfxMan1_bot, OBJ_SIZE_64X64, 1, CHAR_MAN_PAL, -64, -64);

		//////////////////////////////// LOAD WOMAN: /////////////////////////////////////////////////////////////////////////////
		//pallete
		PA_LoadSpritePal(0, CHAR_WOMAN_PAL, (void*)sp_woman_Pal);
		PA_LoadSpritePal(0, CHAR_WOMAN_DIE_PAL, (void*)sp_woman_die_Pal);

		//gfx for top/bot sprites
		u16 GfxWoman1_top = PA_CreateGfx(0, (void*)sp_woman_1a_Sprite, OBJ_SIZE_64X64, 1);
		u16 GfxWoman1_bot = PA_CreateGfx(0, (void*)sp_woman_1b_Sprite, OBJ_SIZE_64X64, 1);

		//woman1 pos 0
		PA_CreateSpriteFromGfx(0, SP_CHAR_WOMAN, GfxWoman1_top, OBJ_SIZE_64X64, 1, CHAR_WOMAN_PAL, -64, -64);
		PA_CreateSpriteFromGfx(0, SP_CHAR_WOMAN+1, GfxWoman1_bot, OBJ_SIZE_64X64, 1, CHAR_WOMAN_PAL, -64, -64);
		//woman1 pos 1
		PA_CreateSpriteFromGfx(0, SP_CHAR_WOMAN+2, GfxWoman1_top, OBJ_SIZE_64X64, 1, CHAR_WOMAN_PAL, -64, -64);
		PA_CreateSpriteFromGfx(0, SP_CHAR_WOMAN+3, GfxWoman1_bot, OBJ_SIZE_64X64, 1, CHAR_WOMAN_PAL, -64, -64);
		//woman1 pos 2
		PA_CreateSpriteFromGfx(0, SP_CHAR_WOMAN+4, GfxWoman1_top, OBJ_SIZE_64X64, 1, CHAR_WOMAN_PAL, -64, -64);
		PA_CreateSpriteFromGfx(0, SP_CHAR_WOMAN+5, GfxWoman1_bot, OBJ_SIZE_64X64, 1, CHAR_WOMAN_PAL, -64, -64);

		//////////////////////////////// LOAD BANDIT1: /////////////////////////////////////////////////////////////////////////////
		//LOAD BANDIT1:
		//pallete
		PA_LoadSpritePal(0, CHAR_BANDIT1_PAL, (void*)sp_bandit1_Pal);
		PA_LoadSpritePal(0, CHAR_BANDIT1_DIE_PAL, (void*)sp_bandit1_die_Pal);

		//gfx for top/bot sprites
		u16 GfxBandit1_top = PA_CreateGfx(0, (void*)sp_bandit1_1a_Sprite, OBJ_SIZE_64X64, 1);
		u16 GfxBandit1_bot = PA_CreateGfx(0, (void*)sp_bandit1_1b_Sprite, OBJ_SIZE_64X64, 1);

		//bandit1 pos 0
		PA_CreateSpriteFromGfx(0, SP_CHAR_BANDIT1,	 GfxBandit1_top, OBJ_SIZE_64X64, 1, CHAR_BANDIT1_PAL, -64, -64);
		PA_CreateSpriteFromGfx(0, SP_CHAR_BANDIT1+1, GfxBandit1_bot, OBJ_SIZE_64X64, 1, CHAR_BANDIT1_PAL, -64, -64);
		//bandit1 pos 1
		PA_CreateSpriteFromGfx(0, SP_CHAR_BANDIT1+2, GfxBandit1_top, OBJ_SIZE_64X64, 1, CHAR_BANDIT1_PAL, -64, -64);
		PA_CreateSpriteFromGfx(0, SP_CHAR_BANDIT1+3, GfxBandit1_bot, OBJ_SIZE_64X64, 1, CHAR_BANDIT1_PAL, -64, -64);
		//bandit1 pos 2
		PA_CreateSpriteFromGfx(0, SP_CHAR_BANDIT1+4, GfxBandit1_top, OBJ_SIZE_64X64, 1, CHAR_BANDIT1_PAL, -64, -64);
		PA_CreateSpriteFromGfx(0, SP_CHAR_BANDIT1+5, GfxBandit1_bot, OBJ_SIZE_64X64, 1, CHAR_BANDIT1_PAL, -64, -64);
	}
	/* ^^^^^^^^^^^^^^^^^^^^^^^^^^^ RELATED TO LEVEL 1 ^^^^^^^^^^^^^^^^^^^^^^^^^^^ */


	/* vvvvvvvvvvvvvvvvvvvvvvvvvvv RELATED TO LEVEL 2 vvvvvvvvvvvvvvvvvvvvvvvvvvv */
	if ( _level >= 2 ) {

	}
	/* ^^^^^^^^^^^^^^^^^^^^^^^^^^^ RELATED TO LEVEL 2 ^^^^^^^^^^^^^^^^^^^^^^^^^^^ */



	/* vvvvvvvvvvvvvvvvvvvvvvvvvvv RELATED TO DUEL STAGE vvvvvvvvvvvvvvvvvvvvvvvvvvv */
	if ( _level == LEVEL_DUEL ) {
		//DUEL BANDIT1
		//pallete
		PA_LoadSpritePal(0, DUEL_BANDIT1_PAL, (void*)sp_bandit_duel1_Pal);
		//gfx for top/bot sprites
		PA_CreateSprite(0, SP_CHAR_DUEL_BANDIT1, (void*)sp_bandit_duel1_a_Sprite, OBJ_SIZE_64X64, 1, DUEL_BANDIT1_PAL, -64, -64);
		PA_CreateSprite(0, SP_CHAR_DUEL_BANDIT1+1, (void*)sp_bandit_duel1_b_Sprite, OBJ_SIZE_64X64, 1, DUEL_BANDIT1_PAL, -64, -64);
		//bandit withdrawing gun:
		PA_CreateSprite(0, SP_CHAR_DUEL_BANDIT1_WITHDRAW, (void*)sp_bandit_duel1_c_Sprite, OBJ_SIZE_64X64, 1, DUEL_BANDIT1_PAL, -64, -64);
		//bandit dying
		PA_CreateSprite(0, SP_CHAR_DUEL_BANDIT1_DYING, (void*)sp_bandit_duel1_dying_Sprite, OBJ_SIZE_64X64, 1, DUEL_BANDIT1_PAL, -64, -64);
		//background
		PA_CreateSprite(0, SP_CHAR_DUEL_BANDIT1_BG, (void*)sp_bandit_duel1_background_Sprite, OBJ_SIZE_64X64, 1, DUEL_BANDIT1_PAL, -64, -64);


		//DUEL BANDIT2
		//pallete
		PA_LoadSpritePal(0, DUEL_BANDIT2_PAL, (void*)sp_bandit_duel2_Pal);
		//gfx for top/bot sprites
		PA_CreateSprite(0, SP_CHAR_DUEL_BANDIT2, (void*)sp_bandit_duel2_a_Sprite, OBJ_SIZE_64X64, 1, DUEL_BANDIT2_PAL, -64, -64);
		PA_CreateSprite(0, SP_CHAR_DUEL_BANDIT2+1, (void*)sp_bandit_duel2_b_Sprite, OBJ_SIZE_64X64, 1, DUEL_BANDIT2_PAL, -64, -64);
		//bandit withdrawing gun:
		PA_CreateSprite(0, SP_CHAR_DUEL_BANDIT2_WITHDRAW, (void*)sp_bandit_duel2_c_Sprite, OBJ_SIZE_64X64, 1, DUEL_BANDIT2_PAL, -64, -64);
		//bandit dying
		PA_CreateSprite(0, SP_CHAR_DUEL_BANDIT2_DYING, (void*)sp_bandit_duel2_dying_Sprite, OBJ_SIZE_64X64, 1, DUEL_BANDIT2_PAL, -64, -64);
		//background
		PA_CreateSprite(0, SP_CHAR_DUEL_BANDIT2_BG, (void*)sp_bandit_duel2_background_Sprite, OBJ_SIZE_64X64, 1, DUEL_BANDIT2_PAL, -64, -64);


		//DUEL BANDIT3
		//pallete
		PA_LoadSpritePal(0, DUEL_BANDIT3_PAL, (void*)sp_bandit_duel3_Pal);
		//gfx for top/bot sprites
		PA_CreateSprite(0, SP_CHAR_DUEL_BANDIT3, (void*)sp_bandit_duel3_a_Sprite, OBJ_SIZE_64X64, 1, DUEL_BANDIT3_PAL, -64, -64);
		PA_CreateSprite(0, SP_CHAR_DUEL_BANDIT3+1, (void*)sp_bandit_duel3_b_Sprite, OBJ_SIZE_64X64, 1, DUEL_BANDIT3_PAL, -64, -64);
		//bandit withdrawing gun:
		PA_CreateSprite(0, SP_CHAR_DUEL_BANDIT3_WITHDRAW, (void*)sp_bandit_duel3_c_Sprite, OBJ_SIZE_64X64, 1, DUEL_BANDIT3_PAL, -64, -64);
		//bandit dying
		PA_CreateSprite(0, SP_CHAR_DUEL_BANDIT3_DYING, (void*)sp_bandit_duel3_dying_Sprite, OBJ_SIZE_64X64, 1, DUEL_BANDIT3_PAL, -64, -64);
		//background
		PA_CreateSprite(0, SP_CHAR_DUEL_BANDIT3_BG, (void*)sp_bandit_duel3_background_Sprite, OBJ_SIZE_64X64, 1, DUEL_BANDIT3_PAL, -64, -64);
	}
	/* ^^^^^^^^^^^^^^^^^^^^^^^^^^^ RELATED TO DUEL STAGE ^^^^^^^^^^^^^^^^^^^^^^^^^^^ */
}

void UIManager::ShowSprite(u8 _id, u8 _x, u8 _y) {
	PA_SetSpriteXY(0, _id, _x, _y);
}

void UIManager::HideSprite(u8 _id) {
	PA_SetSpriteXY(0, _id, -64, -64);
}

//draw a person sprite on the specified door
void UIManager::DrawPerson(u8 _person, u8 _doorId) {
	u8 xPositionPerson = 0;
	u8 yTop = 12; u8 yBot = 76;
	
	//hatman needs different y coordinates
	if ( _person == PERSON_HATMAN ) {
	    yTop += 2;
	    yBot += 2;
	}

	switch(_doorId) {
		case 0: 
			xPositionPerson = 10;
			break;
		case 1: 
			xPositionPerson = 98;
			_person += 2;
			break;
		case 2: 
			xPositionPerson = 185; 
			_person += 4;
			break;
	}
	
	//show person sprite:
	UIManager::ShowSprite(_person, xPositionPerson, yTop);
	UIManager::ShowSprite(_person + 1, xPositionPerson, yBot);
}

void UIManager::ResetDoorGraphics(u8 _person, u8 _doorId) {
	u8 doorSpriteId = 0;

	switch(_doorId) {
		//determines the ID of the sprite animation to be closed
		case 0: 
			doorSpriteId = SP_DOOR_CLOSE;
			break;
		case 1: 
			doorSpriteId = SP_DOOR_CLOSE + 2;
			_person += 2;
			break;
		case 2: 
			doorSpriteId = SP_DOOR_CLOSE + 4;
			_person += 4;
			break;
	}

	//hide sprites from close animation:
	UIManager::HideSprite(doorSpriteId);
	UIManager::HideSprite(doorSpriteId + 1);

	//hide person sprites:
	UIManager::HideSprite(_person);
	UIManager::HideSprite(_person + 1);

	//release memory used by animations (for this door):
	AnimationManager::ReleaseMemory(TAG_PERSON + _doorId, true);
}

//draw a person assault on the specified door
void UIManager::DrawPersonAssault(u8 _personId, u8 _doorId) {
}

//starts the open door animation
//returns a SpriteIDs struct, with the IDs of the animation sprites, so caller can have a reference
SpriteIDs UIManager::PlayOpenDoorAnim(u8 _doorId) {
	u8 xPositionDoor = 0;
	u8 spriteId = 0;
	SpriteIDs myIds;

	switch(_doorId) {
		//determines the left position for the sprite and its ID:
		case 0: 
			xPositionDoor = 13;
			spriteId = SP_DOOR_OPEN;
			break;
		case 1: 
			xPositionDoor = 101; 
			spriteId = SP_DOOR_OPEN + 2;
			break;
		case 2: 
			xPositionDoor = 188; 
			spriteId = SP_DOOR_OPEN + 4;
			break;
	}

	UIManager::ShowSprite(spriteId, xPositionDoor, 12);
	UIManager::ShowSprite(spriteId + 1, xPositionDoor, 76);

	//start open door animation
	PA_StartSpriteAnimEx(0, spriteId, 0, 3, DOOR_SPEED, ANIM_UPDOWN, 1);
	PA_StartSpriteAnimEx(0, spriteId + 1, 0, 3, DOOR_SPEED, ANIM_UPDOWN, 1);

	myIds.arrSpriteID[0] = spriteId;
	myIds.arrSpriteID[1] = spriteId + 1;
	myIds.numberOfIds = 2;

	return myIds;
}

//starts the close door animation
//returns the ID of the animation sprite, so caller can hafe a reference
SpriteIDs UIManager::PlayCloseDoorAnim(u8 _doorId) {
	u8 xPositionDoor = 0;
	u8 spriteIdClose = 0;
	u8 spriteIdOpen = 0;
	SpriteIDs myIds;

	switch(_doorId) {
		//determines the left position for the sprite and its ID:
		case 0: 
			xPositionDoor = 13;
			spriteIdClose = SP_DOOR_CLOSE;
			spriteIdOpen = SP_DOOR_OPEN;
			break;
		case 1: 
			xPositionDoor = 101; 
			spriteIdClose = SP_DOOR_CLOSE + 2;
			spriteIdOpen = SP_DOOR_OPEN + 2;
			break;
		case 2: 
			xPositionDoor = 188; 
			spriteIdClose = SP_DOOR_CLOSE + 4;
			spriteIdOpen = SP_DOOR_OPEN + 4;
			break;
	}

	//start close anim:
	UIManager::ShowSprite(spriteIdClose, xPositionDoor, 12);
	UIManager::ShowSprite(spriteIdClose + 1, xPositionDoor, 76);
	PA_StartSpriteAnimEx(0, spriteIdClose, 0, 3, DOOR_SPEED, ANIM_UPDOWN, 1);
	PA_StartSpriteAnimEx(0, spriteIdClose + 1, 0, 3, DOOR_SPEED, ANIM_UPDOWN, 1);

	//hide Open anim:
	UIManager::HideSprite(spriteIdOpen);
	UIManager::HideSprite(spriteIdOpen + 1);

	myIds.arrSpriteID[0] = spriteIdClose;
	myIds.arrSpriteID[1] = spriteIdClose + 1;
	myIds.numberOfIds = 2;
	
	return myIds;
}

SpriteIDs UIManager::LoadHatmanAnim(u8 _doorPosition) {
    u8 xPos = 10; u8 sp_personId = SP_CHAR_HATMAN;
	SpriteIDs myIds;

    //determines the left position for the sprite
	switch(_doorPosition) {
	    case 1: 
		    xPos = 98;
		    sp_personId += 2;
		    break;
	    case 2: 
		    xPos = 185;
		    sp_personId += 4;
		    break;
    }

	PA_CreateSprite(0, sp_personId, (void*)sp_hatman_top_Sprite, OBJ_SIZE_64X64, 1, CHAR_HATMAN_PAL, -64, -64);
	PA_CreateSprite(0, sp_personId+1, (void*)sp_hatman_bot_Sprite, OBJ_SIZE_64X64, 1, CHAR_HATMAN_PAL, -64, -64);
	PA_StartSpriteAnimEx(0, sp_personId, 0, 6, 0, ANIM_LOOP, 1);

	myIds.arrSpriteID[0] = sp_personId;
	myIds.arrSpriteID[1] = sp_personId + 1;
	myIds.numberOfIds = 2;
	
	//to be released later, by ResetDoorGraphics()
	AnimationManager::RegisterAnimation(sp_personId, 6, TAG_PERSON + _doorPosition);
	AnimationManager::RegisterAnimation(sp_personId+1, 6, TAG_PERSON + _doorPosition);
	
	return myIds;
}

void UIManager::DrawBangScreen() {
	//show BANG! screen
	PA_LoadBackground(0, BG_BANG, &bg_bang);	
	
	sleep(0.2);
	UIManager::FadeOut();
	sleep(1.5);

	//delete bang BG
	PA_DeleteBg(0, BG_BANG);


	// Now that it's all black, clean all that and you're ready to go !
	PA_SetBrightness(0, 0); // normal
	PA_SetBrightness(1, 0); // normal
}

void UIManager::DrawBoomScreen() {
	//show BOOM! screen
	PA_LoadBackground(0, BG_BOOM, &bg_boom);
	
	sleep(0.5);
	UIManager::FadeOut();
	sleep(1.5);

	//delete boom BG
	PA_DeleteBg(0, BG_BOOM);


	// Now that it's all black, clean all that and you're ready to go !
	PA_SetBrightness(0, 0); // normal
	PA_SetBrightness(1, 0); // normal
}

void UIManager::DrawGameOverScreen() {
}

void UIManager::DrawIntroductionAnimation() {
	u16 scrollY = 0;
	
	PA_DualLoadBackground(0, &bg_intro);	//load background image

	sleep(1);
					
	// Scroll background from bottom to top screen
	for (int x=0; x<61; x++) {
		PA_DualBGScrollY(0, scrollY);

		scrollY += 4;
		PA_WaitForVBL();
	}

	//delete background on bottom screen (works on this case?):
	PA_DeleteBg(0, 0);
}

void UIManager::WriteConsiderations() {
	PA_InitText(1, 0);
	sleep(1);
	PA_OutputText(1, 22, 22, (char *)"to Pedro");
	sleep(2);
}

void UIManager::DrawSplashScreens() {
	//previous step was a text background, need to reset
	PA_ResetBgSys();

	// Init a 16 bit Bg on both screens
	PA_Init8bitBg(0, 0);
	PA_Init8bitBg(1, 0);

	//set both screens as black
	PA_SetBrightness(0, -31);
	PA_SetBrightness(1, -31);

	//'DEVELOPED BY' SPLASH SCREEN:
	// Load 2 gifs for 'Developed By' splash screen while hidden
	PA_LoadGif(1, (void*)bg_Splash_developedBy_1);
	PA_LoadGif(0, (void*)bg_Splash_developedBy_2);

	//fade in, wait 1 seconds then fade out
	sleep(1);
	UIManager::FadeIn();
	sleep(1.5);
	UIManager::FadeOut();


	//'POWERED BY PALIB' SPLASH SCREEN:
	// Load 2 gifs for 'Developed By' splash screen while hidden
	PA_LoadGif(1, (void*)bg_palib_1);
	PA_LoadGif(0, (void*)bg_palib_2);
	
	//fade in, wait 1 seconds then fade out
	UIManager::FadeIn();
	sleep(1.7);
	UIManager::FadeOut();
	sleep(1);


	// Now that it's all black, clean all that and you're ready to go !
	PA_SetBrightness(0, 0); // normal
	PA_SetBrightness(1, 0); // normal

	PA_ResetBgSys();
}

void UIManager::DrawMenuOption(u8 _menuOption) {
	//hide all menu options first
	UIManager::HideSprite(SP_MENU_START1);
	UIManager::HideSprite(SP_MENU_START2);
	UIManager::HideSprite(SP_MENU_START3);
	UIManager::HideSprite(SP_MENU_HISCORES1);
	UIManager::HideSprite(SP_MENU_HISCORES2);
	UIManager::HideSprite(SP_MENU_HISCORES3);
	UIManager::HideSprite(SP_MENU_CREDITS1);
	UIManager::HideSprite(SP_MENU_CREDITS2);

	//then, show only the selected option
	switch(_menuOption) {
		case MENU_START_GAME:
			UIManager::ShowSprite(SP_MENU_START1, 89, 60);
			UIManager::ShowSprite(SP_MENU_START2, 121, 60);
			UIManager::ShowSprite(SP_MENU_START3, 153, 60);
			break;

		case MENU_HISCORES:
			UIManager::ShowSprite(SP_MENU_HISCORES1, 94, 84);
			UIManager::ShowSprite(SP_MENU_HISCORES2, 126, 84);
			UIManager::ShowSprite(SP_MENU_HISCORES3, 158, 84);
			break;

		case MENU_CREDITS:
			UIManager::ShowSprite(SP_MENU_CREDITS1, 101, 108);
			UIManager::ShowSprite(SP_MENU_CREDITS2, 133, 108);
			break;
	}
}

void UIManager::PlayPersonDyingAnim(u8 _personId, u8 _doorPosition) {
	u8 sp_dyingId = 0; u8 sp_personId = 0; u8 xPos = 0;

	sp_personId = _personId;

	switch(_doorPosition) {
		//determines the left position for the sprite and its ID:
		case 0: 
			xPos = 10;
			break;
		case 1: 
			xPos = 98;
			sp_dyingId += 2;
			sp_personId += 2;
			break;
		case 2: 
			xPos = 185;
			sp_dyingId += 4;
			sp_personId += 4;
			break;
	}

	switch(_personId) {
		case PERSON_MAN:
			sp_dyingId += SP_CHAR_MAN_DIE;
			PA_CreateSprite(0, sp_dyingId, (void*)sp_man_dying_top_Sprite, OBJ_SIZE_64X64, 1, CHAR_MAN_DIE_PAL, -64, -64);
			PA_CreateSprite(0, sp_dyingId+1, (void*)sp_man_dying_bot_Sprite, OBJ_SIZE_64X64, 1, CHAR_MAN_DIE_PAL, -64, -64);
			break;
		case PERSON_WOMAN:
			sp_dyingId += SP_CHAR_WOMAN_DIE;
			PA_CreateSprite(0, sp_dyingId, (void*)sp_woman_dying_top_Sprite, OBJ_SIZE_64X64, 1, CHAR_WOMAN_DIE_PAL, -64, -64);
			PA_CreateSprite(0, sp_dyingId+1, (void*)sp_woman_dying_bot_Sprite, OBJ_SIZE_64X64, 1, CHAR_WOMAN_DIE_PAL, -64, -64);
			break;
		case PERSON_BANDIT1:
			sp_dyingId += SP_CHAR_BANDIT1_DIE;
			PA_CreateSprite(0, sp_dyingId, (void*)sp_bandit1_die_top_Sprite, OBJ_SIZE_64X64, 1, CHAR_BANDIT1_DIE_PAL, -64, -64);
			PA_CreateSprite(0, sp_dyingId+1, (void*)sp_bandit1_die_bot_Sprite, OBJ_SIZE_64X64, 1, CHAR_BANDIT1_DIE_PAL, -64, -64);
			break;
	}

	//hide current person's sprite:
	UIManager::HideSprite(sp_personId);
	UIManager::HideSprite(sp_personId+1);

	//show dying anim:
	UIManager::ShowSprite(sp_dyingId, xPos, 12);
	UIManager::ShowSprite(sp_dyingId+1, xPos, 56);
	PA_StartSpriteAnimEx(0, sp_dyingId, 0, 1, SPEED_DYING, ANIM_UPDOWN, 1);
	PA_StartSpriteAnimEx(0, sp_dyingId+1, 0, 1, SPEED_DYING, ANIM_UPDOWN, 1);

	//register animation to be released when door graphics is reset:
	AnimationManager::RegisterAnimation(sp_dyingId, 1, TAG_PERSON + _doorPosition);
	AnimationManager::RegisterAnimation(sp_dyingId+1, 1, TAG_PERSON + _doorPosition);
}

void UIManager::DrawShoot(u8 _doorPosition) {
	u8 xPos = 0; u8 spId = 0;

	switch(_doorPosition) {
		case 0:
			xPos = 40;
			break;
		case 1:
			xPos = 127;
			spId += 1;
			break;
		case 2:
			xPos = 215;
			spId += 2;
			break;
	}

	//hide all previous shoot first:
	UIManager::HideSprite(SP_SHOOT);
	UIManager::HideSprite(SP_SHOOT+1);
	UIManager::HideSprite(SP_SHOOT+2);

	//show new shoot sprite:
	UIManager::ShowSprite(SP_SHOOT + spId, xPos, 63);
	PA_StartSpriteAnimEx(0, SP_SHOOT + spId, 0, 2, SPEED_SHOOT, ANIM_UPDOWN, 1);
}

void UIManager::PlayLostLifeAnimation(u8 _numLifes) {
    u8 lifeSpriteID = SP_LIFE + _numLifes - 1;
	u8 xPosition = 162 + (_numLifes * 18);
  
	//blinks life sprite 4 times:
	for (u8 x = 0; x < 4; x++) {
	    
	    //hide last life on screen
	    UIManager::HideSprite(lifeSpriteID);
	    
	    sleep(0.5);

	    //show last life on screen
	    UIManager::ShowSprite(lifeSpriteID, xPosition, 170);
	    
	    sleep(0.5);
    }
}


/*********************************************************************************************************/
//                      Private Methods
/*********************************************************************************************************/
void UIManager::FadeIn() {
	for(s8 i = -31; i <= 0; i++){
		PA_SetBrightness(0, i); 
		PA_SetBrightness(1, i); 
		PA_WaitForVBL();		   
	}
}

void UIManager::FadeOut() {
	for(s8 i = 0; i > -32; i--){
		PA_SetBrightness(0, i); 
		PA_SetBrightness(1, i); 
		PA_WaitForVBL();		   
	}  	
}
