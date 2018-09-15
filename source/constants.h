/* vvvvvvvvvvvvvvvvvvvvvvvvvvv CONSTANTS vvvvvvvvvvvvvvvvvvvvvvvvvvvvvv */
/*	This file defines constants to be used thru the entire game code.	*/
/* ^^^^^^^^^^^^^^^^^^^^^^^^^^^ CONSTANTS ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^ */
#ifndef CONSTANTS_H
#define CONSTANTS_H

/* vvvvvvvvvvvvvvvvvvvvvv 'MAIN LOOP' STATES vvvvvvvvvvvvvvvvvvvvvv */
	#define MAIN_LOOP_SPLASH	0
	#define MAIN_LOOP_INTRO		1
	#define MAIN_LOOP_MENU		2
	#define MAIN_LOOP_CREDITS	3
	#define MAIN_LOOP_HISCORES	4
	#define MAIN_LOOP_GAME		5
	#define MAIN_LOOP_ENTERNAME	6
/* ^^^^^^^^^^^^^^^^^^^^^^^^ 'MAIN LOOP' STATES ^^^^^^^^^^^^^^^^^^^^ */

/* vvvvvvvvvvvvvvvvvvvvvv BACKGROUNDS vvvvvvvvvvvvvvvvvvvvvv */
	#define	BG_MAIN_MENU	0
	#define BG_DUEL_STAGE	1
	#define BG_TEXT			0
	#define BG_STAGE		1
	#define BG_STAGE_DOORS	2
	#define BG_STAGE_DESKS	3
	#define BG_BANG			3
	#define BG_BOOM         3
/* ^^^^^^^^^^^^^^^^^^^^^^ BACKGROUNDS ^^^^^^^^^^^^^^^^^^^^^^ */

/* vvvvvvvvvvvvvvvvvvvvvv SPRITES / ANIMATIONS vvvvvvvvvvvvvvvvvvvvvv */
	//high-priority sprites first:
	#define SP_SHOOT						0
	#define SP_DOOR_OPEN					10
	#define SP_DOOR_CLOSE					16
	#define SP_CHAR_MAN						22
	#define SP_CHAR_BANDIT1					28
	#define SP_CHAR_HATMAN					35
	#define SP_CHAR_WOMAN					45
	#define SP_DOLLAR						55
	#define SP_BIGDOLLAR					70
	#define SP_LIFE							71
	#define SP_ERASE_SCORE					72

	#define SP_MENU_START1					73
	#define SP_MENU_START2					74
	#define SP_MENU_START3					75
	#define SP_MENU_HISCORES1				76
	#define SP_MENU_HISCORES2				77
	#define SP_MENU_HISCORES3				78
	#define SP_MENU_CREDITS1				79
	#define SP_MENU_CREDITS2				80

	#define SP_REDBAR						81
	
	#define SP_CHAR_BANDIT1_DIE				83
	#define SP_CHAR_MAN_DIE					89
	#define SP_CHAR_WOMAN_DIE				95


	#define SP_CHAR_DUEL_BANDIT1_BG			121
	#define SP_CHAR_DUEL_BANDIT2_BG			122
	#define SP_CHAR_DUEL_BANDIT3_BG			123

	#define SP_CHAR_DUEL_BANDIT1_DYING		101
	#define SP_CHAR_DUEL_BANDIT1			103
	#define SP_CHAR_DUEL_BANDIT1_WITHDRAW	105

	#define SP_CHAR_DUEL_BANDIT2_DYING		106
	#define SP_CHAR_DUEL_BANDIT2			108
	#define SP_CHAR_DUEL_BANDIT2_WITHDRAW	110

	#define SP_CHAR_DUEL_BANDIT3_DYING		111
	#define SP_CHAR_DUEL_BANDIT3			113
	#define SP_CHAR_DUEL_BANDIT3_WITHDRAW	115
	
/* ^^^^^^^^^^^^^^^^^^^^^^ SPRITES / ANIMATIONS ^^^^^^^^^^^^^^^^^^^^^^ */

/* vvvvvvvvvvvvvvvvvvvvvv PALETTES vvvvvvvvvvvvvvvvvvvvvv */
	#define CHAR_MAN_PAL			0
	#define CHAR_WOMAN_PAL			1
	#define CHAR_BANDIT1_PAL		2
	#define DOOR_PAL				3
	#define DOLLAR_PAL				4
	#define BIGDOLLAR_PAL			5
	#define LIFE_PAL				6
	#define PAL_MENU				7
	#define CHAR_BANDIT1_DIE_PAL	8
	#define CHAR_MAN_DIE_PAL		9
	#define CHAR_WOMAN_DIE_PAL		10
	#define CHAR_HATMAN_PAL		    11
	#define REDBAR_PAL			    12
	#define DUEL_BANDIT1_PAL		13
	#define DUEL_BANDIT2_PAL		14
	#define DUEL_BANDIT3_PAL		15
/* ^^^^^^^^^^^^^^^^^^^^^^ PALETTES ^^^^^^^^^^^^^^^^^^^^^^ */

/* vvvvvvvvvvvvvvvvvvvvvv PERSON CODES vvvvvvvvvvvvvvvvvvvvvv */
	#define PERSON_NONE			0
	#define PERSON_MAN			SP_CHAR_MAN
	#define PERSON_WOMAN		SP_CHAR_WOMAN
	#define PERSON_BANDIT1		SP_CHAR_BANDIT1
	#define PERSON_HATMAN		SP_CHAR_HATMAN
/* ^^^^^^^^^^^^^^^^^^^^^^ PERSON CODES ^^^^^^^^^^^^^^^^^^^^^^ */

/* vvvvvvvvvvvvvvvvvvvvvv GAME CODES vvvvvvvvvvvvvvvvvvvvvv */
	#define GAME_CODE_NULL				-1
	#define GAME_BANG					0
	#define GAME_KILL_INNOCENT			1
	#define GAME_KILL_BANDIT			2
	#define	GAME_KILL_BOMB				3
	#define	GAME_KILL_MONEY				4
	#define	GAME_KILL_HAT				5
	#define GAME_MONEY					6
	#define GAME_NEXT_LEVEL				7
	#define GAME_DUEL_DIED				8
	#define GAME_DUEL_WON				9
	#define GAME_DUEL_KILL				10
	#define GAME_DUEL_KILL_INNOCENT		11
/* ^^^^^^^^^^^^^^^^^^^^^^ GAME CODES ^^^^^^^^^^^^^^^^^^^^^^ */

/* vvvvvvvvvvvvvvvvvvvvvv DOOR STATUS vvvvvvvvvvvvvvvvvvvvvv */
	#define DOOR_WAITING		9
	#define DOOR_CLOSED			0
	#define DOOR_OPENING		1
	#define DOOR_OPEN			2
	#define DOOR_CLOSING		3
	#define DOOR_JUST_CLOSED	4
/* ^^^^^^^^^^^^^^^^^^^^^^ DOOR STATUS ^^^^^^^^^^^^^^^^^^^^^^ */

/* vvvvvvvvvvvvvvvvvvvvvv MISC vvvvvvvvvvvvvvvvvvvvvv */
	#define DOOR_SPEED			7
	#define SPEED_SHOOT			5
	#define SPEED_DYING			3
/* ^^^^^^^^^^^^^^^^^^^^^^ MISC ^^^^^^^^^^^^^^^^^^^^^^ */

/* vvvvvvvvvvvvvvvvvvvvvv TEXT ENGINE vvvvvvvvvvvvvvvvvvvvvv */
	#define TILETEXT_8X16		1
	#define TILETEXT_16X16		2
/* ^^^^^^^^^^^^^^^^^^^^^^ TEXT ENGINE ^^^^^^^^^^^^^^^^^^^^^^ */

/* vvvvvvvvvvvvvvvvvvvvvv MENU OPTIONS SPRITES vvvvvvvvvvvvvvvvvvvvvv */
	#define MENU_START_GAME		0
	#define MENU_HISCORES		1
	#define MENU_CREDITS		2
/* ^^^^^^^^^^^^^^^^^^^^^^ MENU OPTIONS SPRITES ^^^^^^^^^^^^^^^^^^^^^^ */

/* vvvvvvvvvvvvvvvvvvvvvv DOOR SCROLLING vvvvvvvvvvvvvvvvvvvvvv */
	#define SCROLL_LEFT		-1
	#define SCROLL_RIGHT	1
/* ^^^^^^^^^^^^^^^^^^^^^^ DOOR SCROLLING ^^^^^^^^^^^^^^^^^^^^^^ */

/* vvvvvvvvvvvvvvvvvvvvvv ANIMATION MANAGEMENT CATEGORIES vvvvvvvvvvvvvvvvvvvvvv */
	#define	TAG_ALL			200
	#define	TAG_PERSON		0
/* ^^^^^^^^^^^^^^^^^^^^^^ ANIMATION MANAGEMENT CATEGORIES ^^^^^^^^^^^^^^^^^^^^^^ */

/* vvvvvvvvvvvvvvvvvvvvvv SCORE CODES vvvvvvvvvvvvvvvvvvvvvv */
	//LEVEL 1:
	#define SCORE_LEVEL1_MAN			50
	#define SCORE_LEVEL1_WOMAN			40
	#define SCORE_LEVEL1_HATMAN_HAT		10
	#define SCORE_LEVEL1_HATMAN_MONEY	200
	#define SCORE_LEVEL1_HATMAN			100
	#define SCORE_LEVEL1_BANDIT1		80
/* ^^^^^^^^^^^^^^^^^^^^^^ SCORE CODES ^^^^^^^^^^^^^^^^^^^^^^ */

/* vvvvvvvvvvvvvvvvvvvvvv LEVEL vvvvvvvvvvvvvvvvvvvvvv */
	#define LEVEL_DUEL					-1
	#define LEVEL_NOT_IN_GAME			0 //like: menu, hiscores, etc

/* ^^^^^^^^^^^^^^^^^^^^^^ LEVEL ^^^^^^^^^^^^^^^^^^^^^^ */


/* vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv DUEL STAGE vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv */
	#define LOOP_RUNNING	0
	#define	LOOP_EXIT		1
/* ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^ DUEL STAGE ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^ */
#endif