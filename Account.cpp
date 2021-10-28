#include "./models/Account.h"
#include "Auxiliar.h"
#include <string>
#include <time.h>
#include <chrono>
#include <ctime>


Account::Account(int _id, int account_Num, const std::string& firstName, const std::string& lastName, float _balance, const std::string& currency, std::string openingDate, bool _active) : id{ _id }, accountNumber{ account_Num },  balance{ _balance }{

	setFirstName( firstName ); 
	setLastName( lastName );
	openingDate=getCurrentDate();
	setOpeningDate(openingDate);
	setCurrency(currency);
}


int Account::getId()const {
	return id;
}

void Account::setId(int _id) {
	id = _id;

}

float Account::getBalance()const {
	return balance;
}

std::string Account::getFirstName()const {
	return firstName;
}

void Account::setFirstName(const std::string& firstNameString) {

	size_t lenght{ firstNameString.size() };
	lenght = (lenght < 10 ? lenght : 9);
	firstNameString.copy(firstName, lenght);
	firstName[lenght] = '\0';
}

std::string Account::getLastName()const {
	return lastName;
}

void Account::setLastName(const std::string& lastNameString) {

	size_t lenght{ lastNameString.size() };
	lenght = (lenght < 10 ? lenght : 9);
	lastNameString.copy(lastName, lenght);
	lastName[lenght] = '\0';
}

std::string Account::getCurrency()const {
	return currency;
}

void Account::setCurrency(const std::string& currencyString) {

	size_t lenght{ currencyString.size() };
	lenght = (lenght < 10 ? lenght : 9);
	currencyString.copy(currency, lenght);
	currency[lenght] = '\0';
}

int Account::getAccountNumber()const {
	return accountNumber;
}

void Account::setAccountNumber() {
	int iRand{ 0 };
	srand(time(NULL));
	for (int i = 0; i < 8; i++) {
		iRand = iRand + (rand() % 900000000 + 100000000);
	}
	accountNumber = iRand;
}

bool Account::getState() {
	return active;
}

void Account::setState(bool _active) {
	active = _active;
}

std::string Account::getOpeningDate() {
	return openingDate;
}

void Account::setOpeningDate(const std::string openingDateString) {

	size_t lenght{ openingDateString.size() };
	lenght = (lenght < 10 ? lenght : 9);
	openingDateString.copy(openingDate, lenght);
	openingDate[lenght] = '\0';
}



void Account::deposit(float depositAmount) {
	if (depositAmount > 0) {
		balance = balance + depositAmount;
	}
}

void Account::withraw(float withrawAmount) {
	if (withrawAmount > 0) {
		balance = balance - withrawAmount;
	}
}

