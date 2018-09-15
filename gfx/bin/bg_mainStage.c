#include <PA_BgStruct.h>

extern const char bg_mainStage_Tiles[];
extern const char bg_mainStage_Map[];
extern const char bg_mainStage_Pal[];

const PA_BgStruct bg_mainStage = {
	PA_BgNormal,
	256, 192,

	bg_mainStage_Tiles,
	bg_mainStage_Map,
	{bg_mainStage_Pal},

	5824,
	{1536}
};
