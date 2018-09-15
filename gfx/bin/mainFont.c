#include <PA_BgStruct.h>

extern const char mainFont_Tiles[];
extern const char mainFont_Map[];
extern const char mainFont_Pal[];

const PA_BgStruct mainFont = {
	PA_BgNormal,
	256, 192,

	mainFont_Tiles,
	mainFont_Map,
	{mainFont_Pal},

	8192,
	{1536}
};
