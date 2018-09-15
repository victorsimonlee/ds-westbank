#include "ConfigPerson.h"

ConfigPerson::ConfigPerson(void) {
}

ConfigPerson::~ConfigPerson(void) {
}

void ConfigPerson::SetCode(u8 _code) {
	this->myCode = _code;
}

u8 ConfigPerson::GetCode() {
	return this->myCode;
}

void ConfigPerson::SetDoorOpenAmmount(u8 _ammount) {
	this->myDoorOpenAmmount = _ammount;
}

u8 ConfigPerson::GetDoorOpenAmmount() {
	return this->myDoorOpenAmmount;
}