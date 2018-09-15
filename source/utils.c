/* General Purpose Functions */
#include <PA9.h>

void sleep(double _seconds) {
	s16 time = _seconds * 60;
	while(time) {
		time--;
		PA_WaitForVBL();
	}		
}


void debug(char *_str, u32 _num) {
	static u8 yPos = 0;

	if ( yPos == 0 )
		PA_InitText(1, 0);

	//display level info
	PA_OutputText(1, 0, yPos, "%s %d", _str, _num);
	//PA_OutputText(1, 0, yPos, "teste");

	if ( yPos < 19 )
		yPos += 2;
	else
		yPos = 0;
}
