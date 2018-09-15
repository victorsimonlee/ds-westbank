#include <PA_BgStruct.h>

extern const char bg_bang_Tiles[];
extern const char bg_bang_Map[];
extern const char bg_bang_Pal[];

const PA_BgStruct bg_bang = {
	PA_BgNormal,
	256, 192,

	bg_bang_Tiles,
	bg_bang_Map,
	{bg_bang_Pal},

	38528,
	{1536}
};
