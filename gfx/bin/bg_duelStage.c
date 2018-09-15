#include <PA_BgStruct.h>

extern const char bg_duelStage_Tiles[];
extern const char bg_duelStage_Map[];
extern const char bg_duelStage_Pal[];

const PA_BgStruct bg_duelStage = {
	PA_BgNormal,
	256, 192,

	bg_duelStage_Tiles,
	bg_duelStage_Map,
	{bg_duelStage_Pal},

	23744,
	{1536}
};
