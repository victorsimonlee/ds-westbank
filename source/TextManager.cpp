#include "TextManager.h"

TextManager::TextManager(u8 _screen, u8 _bg) {
    this->myScreen = _screen;
    this->myBg = _bg;
	this->rowOffset = 32;
	this->InitSpriteFontArray(_screen, TILETEXT_8X16);  //initialize the global array
}

TextManager::~TextManager(void) {
	//DELETE BACKGROUND!
}

void TextManager::PrintText(u8 _x, u8 _y, char* _text) {
	this->PrintText(_x, _y, _text, true);
}

void TextManager::PrintText(u8 _x, u8 _y, char* _text, bool _clearBg) {  //TODO: param to clear the BG or not
	if (_clearBg) {
		// Delete background's tile_map
		PA_ClearBg(this->myScreen, this->myBg);
	}

	u8 c = 0;
	u8 charStartIndex = 0;

	for (c=0; c<strlen(_text); c++) {
		charStartIndex = arrIdx[_text[c]];

		//top left
		PA_SetMapTile(this->myScreen, this->myBg, _x, _y, charStartIndex);		//screen,bg,x,y,tile

        //keep same char code if SPACE
        if ( charStartIndex > 0 ) {
		    charStartIndex += rowOffset;
		}

		if ( textSize == TILETEXT_16X16 ) {
			//top right
			PA_SetMapTile(this->myScreen, this->myBg, _x+1, _y, charStartIndex + 1);
			//bottom right
			PA_SetMapTile(this->myScreen, this->myBg, _x+1, _y+1, charStartIndex + 1);
		}

		//bottom left
		PA_SetMapTile(this->myScreen, this->myBg, _x, _y+1, charStartIndex);

		_x += textSize;
	}
}


//_textSize: SPTEXT_8X16, SPTEXT_16X16
void TextManager::InitSpriteFontArray(u8 _screen, u8 _textSize) {
	// Load the Background (set screen to black before load, because BG may appear on screen):
	PA_SetBrightness(_screen, -32); 
	PA_LoadBackground(_screen, this->myBg, &mainFont);
	PA_ClearBg(this->myScreen, this->myBg);
	PA_SetBrightness(_screen, 0); 

	u8 x,y = 0;
	rowOffset = rowOffset * _textSize;
	textSize = _textSize;

	//initialize numbers from 0-9
	for (x='0'; x<='9'; x++) {
		arrIdx[x] = _textSize + y;
		y++;
	}

	//chars a-u
	for (x='a'; x<='u'; x++) {
		arrIdx[x] = _textSize + y;
		y++;
	}

	y += rowOffset;

	//chars v-z
	for (x='v'; x<='z'; x++) {
		arrIdx[x] = _textSize + y;
		y++;
	}
	
	//space
	arrIdx[' '] = 0;
}