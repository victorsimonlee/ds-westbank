#pragma once

#include <PA9.h>
#include "Types.h"
#include "utils.h"
#include "constants.h"
#include "AnimationManager.h"

//includes for graphics
#include "all_gfx.h"


class UIManager {
	public:
		UIManager(void);
		~UIManager(void);

		static void LoadSprites(s8 _level);
		static void ShowSprite(u8 _id, u8 _x, u8 _y);
		static void HideSprite(u8 _id);

		//sprites
		static void DrawPerson(u8 _person, u8 _doorId); //draw a person sprite on the specified door
		static void ResetDoorGraphics(u8 _personId, u8 _doorId); //remove a person sprite from the specified door
		static void DrawPersonAssault(u8 _personId, u8 _doorId); //draw a person assault on the specified door
		static void DrawMenuOption(u8 _menuOption); //draw a menu option sprite
		static void DrawShoot(u8 _doorPosition); //draw player shoot sprite
		static SpriteIDs LoadHatmanAnim(u8 _doorPosition); //draw HATMAN animation on frame1 and return the spriteID to caller

		//animations
		static SpriteIDs PlayOpenDoorAnim(u8 _doorId);
		static SpriteIDs PlayCloseDoorAnim(u8 _doorId);
		static void PlayPersonDyingAnim(u8 _personId, u8 _doorPosition);
		static void PlayLostLifeAnimation(u8 _numLifes);

		//Backgrounds
		static void DrawBangScreen();
		static void DrawBoomScreen();
		static void DrawGameOverScreen();
		static void DrawSplashScreens();
		static void DrawIntroductionAnimation(); //the background sliding animation
		static void WriteConsiderations(); //write 'To Pedro'
		static void showCredits();	
		static void showHiscores();

	private:
		static void FadeIn();
		static void FadeOut();
};