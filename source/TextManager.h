#pragma once

#include <PA9.h>
// Graphics converted using PAGfx
#include "all_gfx.h"

#include "constants.h"
#include "utils.h"


class TextManager {
	public:
		u8 arrIdx[255];
		u8 rowOffset; //32 for a full row (default for my games. Fill unused tiles with a unique color)
		u8 textSize;
		u8 myBg;
		u8 myScreen;


		TextManager(u8 _screen, u8 _bg);
		~TextManager(void);

		void PrintText(u8 _x, u8 _y, char* _text);
		void PrintText(u8 _x, u8 _y, char* _text, bool _clearBg);

	private:
		void InitSpriteFontArray(u8 _screen, u8 _textSize);
};
