#include <PA_BgStruct.h>

extern const char bg_doors_Tiles[];
extern const char bg_doors_Map[];
extern const char bg_doors_Pal[];

const PA_BgStruct bg_doors = {
	PA_BgNormal,
	256, 192,

	bg_doors_Tiles,
	bg_doors_Map,
	{bg_doors_Pal},

	20928,
	{1536}
};
