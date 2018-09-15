#include <PA_BgStruct.h>

extern const char bg_boom_Tiles[];
extern const char bg_boom_Map[];
extern const char bg_boom_Pal[];

const PA_BgStruct bg_boom = {
	PA_BgNormal,
	256, 192,

	bg_boom_Tiles,
	bg_boom_Map,
	{bg_boom_Pal},

	26688,
	{1536}
};
