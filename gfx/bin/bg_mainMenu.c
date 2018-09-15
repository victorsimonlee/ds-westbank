#include <PA_BgStruct.h>

extern const char bg_mainMenu_Tiles[];
extern const char bg_mainMenu_Map[];
extern const char bg_mainMenu_Pal[];

const PA_BgStruct bg_mainMenu = {
	PA_BgNormal,
	256, 192,

	bg_mainMenu_Tiles,
	bg_mainMenu_Map,
	{bg_mainMenu_Pal},

	10752,
	{1536}
};
