#include <PA_BgStruct.h>

extern const char bg_intro_Tiles[];
extern const char bg_intro_Map[];
extern const char bg_intro_Pal[];

const PA_BgStruct bg_intro = {
	PA_BgNormal,
	256, 512,

	bg_intro_Tiles,
	bg_intro_Map,
	{bg_intro_Pal},

	51264,
	{4096}
};
