//Gfx converted using Mollusk's PAGfx Converter

//This file contains all the .h, for easier inclusion in a project

#ifndef ALL_GFX_H
#define ALL_GFX_H

#ifndef PAGfx_struct
    typedef struct{
    void *Map;
    int MapSize;
    void *Tiles;
    int TileSize;
    void *Palette;
    int *Info;
} PAGfx_struct;
#endif


// Sprite files : 
extern const unsigned char sp_dolar_Sprite[256] __attribute__ ((aligned (4))) ;  // Pal : sp_dollar_Pal
extern const unsigned char sp_guMenu_Sprite[2048] __attribute__ ((aligned (4))) ;  // Pal : sp_guMenu_Pal
extern const unsigned char sp_life_Sprite[512] __attribute__ ((aligned (4))) ;  // Pal : sp_life_Pal
extern const unsigned char sp_doorsClose_bot_Sprite[16384] __attribute__ ((aligned (4))) ;  // Pal : sp_doors_Pal
extern const unsigned char sp_doorsClose_top_Sprite[16384] __attribute__ ((aligned (4))) ;  // Pal : sp_doors_Pal
extern const unsigned char sp_doorsOpen_bot_Sprite[16384] __attribute__ ((aligned (4))) ;  // Pal : sp_doors_Pal
extern const unsigned char sp_doorsOpen_top_Sprite[16384] __attribute__ ((aligned (4))) ;  // Pal : sp_doors_Pal
extern const unsigned char sp_man1_1a_Sprite[4096] __attribute__ ((aligned (4))) ;  // Pal : sp_man1_Pal
extern const unsigned char sp_man1_1b_Sprite[4096] __attribute__ ((aligned (4))) ;  // Pal : sp_man1_Pal
extern const unsigned char sp_BigDollar_Sprite[1024] __attribute__ ((aligned (4))) ;  // Pal : sp_BigDollar_Pal
extern const unsigned char sp_woman1_1b_Sprite[4096] __attribute__ ((aligned (4))) ;  // Pal : sp_woman1_Pal
extern const unsigned char sp_woman1_1a_Sprite[4096] __attribute__ ((aligned (4))) ;  // Pal : sp_woman1_Pal
extern const unsigned char sp_bandit1_1b_Sprite[4096] __attribute__ ((aligned (4))) ;  // Pal : sp_bandit1_Pal
extern const unsigned char sp_bandit1_1a_Sprite[4096] __attribute__ ((aligned (4))) ;  // Pal : sp_bandit1_Pal

// Background files : 
extern const int bg_doors_Info[3]; // BgMode, Width, Height
extern const unsigned short bg_doors_Map[4096] __attribute__ ((aligned (4))) ;  // Pal : bg_doors_Pal
extern const unsigned char bg_doors_Tiles[27520] __attribute__ ((aligned (4))) ;  // Pal : bg_doors_Pal
extern PAGfx_struct bg_doors; // background pointer

extern const int bg_desks_Info[3]; // BgMode, Width, Height
extern const unsigned short bg_desks_Map[768] __attribute__ ((aligned (4))) ;  // Pal : bg_desks_Pal
extern const unsigned char bg_desks_Tiles[4288] __attribute__ ((aligned (4))) ;  // Pal : bg_desks_Pal
extern PAGfx_struct bg_desks; // background pointer

extern const int bg_intro_Info[3]; // BgMode, Width, Height
extern const unsigned short bg_intro_Map[2048] __attribute__ ((aligned (4))) ;  // Pal : bg_intro_Pal
extern const unsigned char bg_intro_Tiles[51264] __attribute__ ((aligned (4))) ;  // Pal : bg_intro_Pal
extern PAGfx_struct bg_intro; // background pointer

extern const int bg_mainMenu_Info[3]; // BgMode, Width, Height
extern const unsigned short bg_mainMenu_Map[768] __attribute__ ((aligned (4))) ;  // Pal : bg_mainMenu_Pal
extern const unsigned char bg_mainMenu_Tiles[10176] __attribute__ ((aligned (4))) ;  // Pal : bg_mainMenu_Pal
extern PAGfx_struct bg_mainMenu; // background pointer

extern const int bg_mainStage_Info[3]; // BgMode, Width, Height
extern const unsigned short bg_mainStage_Map[768] __attribute__ ((aligned (4))) ;  // Pal : bg_mainStage_Pal
extern const unsigned char bg_mainStage_Tiles[8640] __attribute__ ((aligned (4))) ;  // Pal : bg_mainStage_Pal
extern PAGfx_struct bg_mainStage; // background pointer


// Palette files : 
extern const unsigned short sp_dollar_Pal[6] __attribute__ ((aligned (4))) ;
extern const unsigned short sp_guMenu_Pal[129] __attribute__ ((aligned (4))) ;
extern const unsigned short sp_life_Pal[27] __attribute__ ((aligned (4))) ;
extern const unsigned short sp_doors_Pal[206] __attribute__ ((aligned (4))) ;
extern const unsigned short sp_man1_Pal[39] __attribute__ ((aligned (4))) ;
extern const unsigned short sp_BigDollar_Pal[34] __attribute__ ((aligned (4))) ;
extern const unsigned short sp_woman1_Pal[231] __attribute__ ((aligned (4))) ;
extern const unsigned short sp_bandit1_Pal[232] __attribute__ ((aligned (4))) ;
extern const unsigned short bg_doors_Pal[170] __attribute__ ((aligned (4))) ;
extern const unsigned short bg_desks_Pal[104] __attribute__ ((aligned (4))) ;
extern const unsigned short bg_intro_Pal[242] __attribute__ ((aligned (4))) ;
extern const unsigned short bg_mainMenu_Pal[137] __attribute__ ((aligned (4))) ;
extern const unsigned short bg_mainStage_Pal[89] __attribute__ ((aligned (4))) ;


#endif

