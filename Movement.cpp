#include "Movement.h"
#include <string>

Movement::Movement(int _movId, const std::string& movType, const std::string& movCurrency, float _movValue, int _accountNumber) : movId{ _movId }, movValue{ _movValue }, accountNumber{ _accountNumber }{
	setMovType(movType);
	setMovCurrency(movCurrency);
}


int Movement::getId()const{
	return movId;
}
void Movement::setId(int _movId){
	movId = _movId;
}


std::string Movement::getMovType()const {
	return movType;
}

void Movement::setMovType(const std::string& movTypeString) {

	size_t lenght{ movTypeString.size() };
	lenght = (lenght < 4 ? lenght : 3);
	movTypeString.copy(movType, lenght);
	movType[lenght] = '\0';
}

std::string Movement::getMovCurrency()const{
	return movCurrency;
}
void Movement::setMovCurrency(const std::string& movCurrencyString){
	size_t lenght{ movCurrencyString.size() };
	lenght = (lenght < 4 ? lenght : 3);
	movCurrencyString.copy(movCurrency, lenght);
	movCurrency[lenght] = '\0';
}

float Movement::getMovValue()const{
	return movValue;
}
void Movement::setMovValue(float _movValue){
	movValue = _movValue;
}

int Movement::getAccountNumber()const{
	return accountNumber;
}
void Movement::setAccountNumber(int _accountNumber){
	accountNumber = _accountNumber;
}