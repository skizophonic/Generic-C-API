#pragma once

#include "File.h"
#include "Account.h"
#include "Movement.h"
#include "Settings.h"
#include <iostream>

File<Movement> fileMovConnection() {
	File<Movement> file("Movements.dat");
	return file;
}

int transactionMov(std::string movType) {

	int accountId{ 0 };
	int movCount{ 0 };
	File<Settings> settingsFile("Settings.dat");
	File<Movement> movFile = fileMovConnection();
	File<Account>accountFile ("Accounts.dat");
	std::string movCurrency;
	float amount;
	int movId{ 1 };
	int accountNumber{ 0 };
	Movement newMovement;
	Account accountToChange;
	Settings settings;

	std::multimap<int, Account>* mapPointer;
	std::multimap<int, Account> map;
	mapPointer = &map;

	std::cout << "Insert the Account Number: " << std::endl;
	std::cin.ignore();
	std::cin >> accountNumber;

	accountFile.putIntoMap(mapPointer);

	std::multimap<int, Account>::iterator it = map.begin();
	for (; it != map.end(); it++)
	{
		if (it->second.getAccountNumber() == accountNumber) {
			accountToChange = it->second;
		}
	}
		std::cout << "\nEnter the transaction amount:\n";
		std::cin >> amount;

		if (movType == "DEP") {
			accountToChange.deposit(amount);
		}

		if (movType == "LEV") {
			accountToChange.withraw(amount);
		}
		
		settingsFile.readRecord(settings, 2);
		settings.setRecordNumber(settings.getRecordNumber());
		movCount = settings.getRecordNumber();
		settingsFile.createRecord(settings, 2);
		settingsFile.closeFile();

		newMovement.setId(movCount);
		newMovement.setMovType(movType);
		newMovement.setMovCurrency(accountToChange.getCurrency());
		newMovement.setAccountNumber(accountNumber);
		newMovement.setMovValue(amount);

		accountId = accountToChange.getId();
		map.clear();
		accountFile.readRecord(accountToChange, accountId);
		accountFile.createRecord(accountToChange, accountId);
		movFile.createRecord(newMovement, movId);
		movFile.closeFile();
		accountFile.closeFile();

	std::cout << "\nMOVEMENT" << movType << " Value: " << amount << " Account: "<< accountToChange.getAccountNumber()<< std::endl <<" Balance: " << accountToChange.getBalance() << " "<< accountToChange.getCurrency()<< std::endl;
	
	accountFile.pauseExecution();
	
	return 0;
}


void listAllMovements() {

	std::multimap<int, Movement>* mapPointer;
	File<Movement> movFile("Movements.dat");

	std::multimap<int, Movement> map;
	mapPointer = &map;

	movFile.putIntoMap(mapPointer);
	
	std::multimap<int, Movement>::iterator it = map.begin();
	std::cout << map.size() << std::endl;

	for (; it != map.end(); it++)
	{
		std::cout << it->second << std::endl;
	}
	movFile.pauseExecution();
}



void listMovements() {
	int accountNumber{ 0 };
	std::multimap<int, Movement>* mapPointer;
	File<Movement> movFile("Movements.dat");

	std::multimap<int, Movement> map;
	mapPointer = &map;
	std::cout << "Insert the account number: " << std::endl;
	std::cin.ignore();
	std::cin >> accountNumber;

	movFile.putIntoMap(mapPointer);

	std::multimap<int, Movement>::iterator it = map.begin();
	std::cout << map.size() << std::endl;

	for (; it != map.end(); it++)
	{
		if (it->second.getAccountNumber() == accountNumber) {
			std::cout << it->second << std::endl;
		}
	}
	movFile.pauseExecution();
}


void transferMov() {

	File<Account> accountFile("Accounts.dat");
	File<Settings> settingsFile("Settings.dat");
	File<Movement> movFile = fileMovConnection();
	Settings settings;
	Movement newOutMovement;
	Movement newInMovement;
	Account originAccount;
	Account destinationAccount;
	std::multimap<int, Account>* mapPointer;
	std::multimap<int, Account> map;
	mapPointer = &map;
	std::string movType{ "TRS" };
	int movCount{ 0 };
	int accountId{ 0 };
	int originAccountId{ 0 };
	int destinationAccountId{ 0 };
	float amount{ 0.0 };
	std::cout << ("Insert the source account number:\n");
	std::cin.ignore();
	std::cin >> originAccountId;

	accountFile.putIntoMap(mapPointer);
	std::multimap<int, Account>::iterator it = map.begin();
	for (; it != map.end(); it++)
	{
		if (it->second.getAccountNumber() == accountId) {
			originAccount = it->second;
		}
	}

	map.clear();

	std::cout << "\nEnter the transaction amount:\n";
	std::cin >> amount;

	std::cout << ("Insert the target account number:\n");
	std::cin.ignore();
	std::cin >> destinationAccountId;

	accountFile.putIntoMap(mapPointer);
	for (; it != map.end(); it++)
	{
		if (it->second.getAccountNumber() == accountId) {
			destinationAccount = it->second;
		}
	}
	
	map.clear();
	accountFile.readRecord(originAccount, originAccount.getId());
	originAccount.withraw(amount);
	accountFile.createRecord(originAccount, originAccount.getId());

	accountFile.readRecord(destinationAccount, destinationAccount.getId());
	destinationAccount.deposit(amount);
	accountFile.createRecord(destinationAccount, destinationAccount.getId());

	settingsFile.readRecord(settings, 2);
	settings.setRecordNumber(settings.getRecordNumber());
	movCount = settings.getRecordNumber();
	settingsFile.createRecord(settings, 2);
	settingsFile.closeFile();

	newOutMovement.setId(movCount);
	newOutMovement.setMovType(movType);
	newOutMovement.setMovCurrency(originAccount.getCurrency());
	newOutMovement.setAccountNumber(originAccount.getAccountNumber());
	newOutMovement.setMovValue(amount);
	movFile.createRecord(newOutMovement, movCount);

	settingsFile.readRecord(settings, 2);
	settings.setRecordNumber(settings.getRecordNumber());
	movCount = settings.getRecordNumber();
	settingsFile.createRecord(settings, 2);
	settingsFile.closeFile();

	newInMovement.setId(movCount);
	newInMovement.setMovType(movType);
	newInMovement.setMovCurrency(destinationAccount.getCurrency());
	newInMovement.setAccountNumber(destinationAccount.getAccountNumber());
	newInMovement.setMovValue(amount);
	movFile.createRecord(newInMovement, movCount);
	/*
	accountId = accountToChange.getId();
	map.clear();
	accountFile.readRecord(accountToChange, accountId);
	accountFile.createRecord(accountToChange, accountId);
	movFile.createRecord(newMovement, movCount);
	*/
	movFile.closeFile();
	accountFile.closeFile();

	std::cout << "\nTRANSFER " << " Amount: " << amount << "Source Account: " << originAccount.getAccountNumber() << "Target Account: " << destinationAccount.getAccountNumber() << std::endl;
	accountFile.pauseExecution();
}

