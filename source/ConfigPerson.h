#pragma once
#include "constants.h"
#include "utils.h"

class ConfigPerson {

private:
	u8 myCode;
	u8 myDoorOpenAmmount;  //how long a door should remain open for current person

public:
	ConfigPerson(void);
	~ConfigPerson(void);


	void SetCode(u8 _code);
	u8 GetCode();

	void SetDoorOpenAmmount(u8 _ammount);
	u8 GetDoorOpenAmmount();
};