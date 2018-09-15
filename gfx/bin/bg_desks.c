#include <PA_BgStruct.h>

extern const char bg_desks_Tiles[];
extern const char bg_desks_Map[];
extern const char bg_desks_Pal[];

const PA_BgStruct bg_desks = {
	PA_BgNormal,
	256, 192,

	bg_desks_Tiles,
	bg_desks_Map,
	{bg_desks_Pal},

	4288,
	{1536}
};
