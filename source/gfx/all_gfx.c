//Gfx converted using Mollusk's PAGfx Converter

//This file contains all the .c, for easier inclusion in a project

#ifdef __cplusplus
extern "C" {
#endif

#include "all_gfx.h"


// Sprite files : 
#include "sp_dolar.c"
#include "sp_guMenu.c"
#include "sp_life.c"
#include "sp_doorsClose_bot.c"
#include "sp_doorsClose_top.c"
#include "sp_doorsOpen_bot.c"
#include "sp_doorsOpen_top.c"
#include "sp_man1_1a.c"
#include "sp_man1_1b.c"
#include "sp_BigDollar.c"
#include "sp_woman1_1b.c"
#include "sp_woman1_1a.c"
#include "sp_bandit1_1b.c"
#include "sp_bandit1_1a.c"

// Background files : 
#include "bg_doors.c"
#include "bg_desks.c"
#include "bg_intro.c"
#include "bg_mainMenu.c"
#include "bg_mainStage.c"

// Palette files : 
#include "sp_dollar.pal.c"
#include "sp_guMenu.pal.c"
#include "sp_life.pal.c"
#include "sp_doors.pal.c"
#include "sp_man1.pal.c"
#include "sp_BigDollar.pal.c"
#include "sp_woman1.pal.c"
#include "sp_bandit1.pal.c"
#include "bg_doors.pal.c"
#include "bg_desks.pal.c"
#include "bg_intro.pal.c"
#include "bg_mainMenu.pal.c"
#include "bg_mainStage.pal.c"

// Background Pointers :
PAGfx_struct bg_doors = {(void*)bg_doors_Map, 4096, (void*)bg_doors_Tiles, 27520, (void*)bg_doors_Pal, (int*)bg_doors_Info };
PAGfx_struct bg_desks = {(void*)bg_desks_Map, 768, (void*)bg_desks_Tiles, 4288, (void*)bg_desks_Pal, (int*)bg_desks_Info };
PAGfx_struct bg_intro = {(void*)bg_intro_Map, 2048, (void*)bg_intro_Tiles, 51264, (void*)bg_intro_Pal, (int*)bg_intro_Info };
PAGfx_struct bg_mainMenu = {(void*)bg_mainMenu_Map, 768, (void*)bg_mainMenu_Tiles, 10176, (void*)bg_mainMenu_Pal, (int*)bg_mainMenu_Info };
PAGfx_struct bg_mainStage = {(void*)bg_mainStage_Map, 768, (void*)bg_mainStage_Tiles, 8640, (void*)bg_mainStage_Pal, (int*)bg_mainStage_Info };


#ifdef __cplusplus
}
#endif

