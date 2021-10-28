#pragma once

#include "Account.h"
#include "File.h"
#include <iostream>
#include <iomanip>
#include "Settings.h"

int insertAccount() {
	File<Settings> settingsFile("Settings.dat");
	File<Account> file("Accounts.dat");
	
	float depAmount{ 0 };
	int id{ 0 };
	std::string firstName{""};
	std::string lastName{ "" };
	std::string currency{ "" };

	Settings settings;
	Account newAccount;

	std::cout << "Insert the name of the account holder: " << std::endl;
	std::cout << "Type the first name: " << std::endl;
	std::cin.ignore();
	std::getline(std::cin, firstName);
	
	std::cout << "Type the last name: " << std::endl;
	std::getline(std::cin, lastName);

	std::cout << "Insert the currency: " << std::endl;
	std::getline(std::cin, currency);
	
	std::cout << "\nInsert the opening balance:\n";
	std::cin >> depAmount;
	
	
	
	int accountNum = newAccount.getAccountNumber();
	
	newAccount.setFirstName(firstName);
	newAccount.setLastName(lastName);
	newAccount.deposit(depAmount);
	newAccount.setAccountNumber();
	newAccount.setCurrency(currency);


	std::cout << "HOLDER: " << newAccount.getFirstName() << " " << newAccount.getLastName() << std::endl;
	std::cout << "\nOpening Balance: " << depAmount << currency <<"\n" << std::endl;

	settingsFile.readRecord(settings, 1);
	settings.setRecordNumber(settings.getRecordNumber());
	id = settings.getRecordNumber();
	settingsFile.createRecord(settings, 1);
	settingsFile.closeFile();
	newAccount.setId(id);

	file.createRecord(newAccount, id);

	file.closeFile();
	file.pauseExecution();
	
	return 0;
}


void listAccount() {

	Account account;
	File<Account> file("Accounts.dat");

	std::multimap<int, Account>* mapPointer;
	std::multimap<int, Account> map;
	mapPointer = &map;

	int accountId{ 0 };
	int id{ 0 };
	std::cout << ("Insert the number of the account to consult:\n");
	std::cin.ignore();
	std::cin >> accountId;

	file.putIntoMap(mapPointer);

	std::multimap<int, Account>::iterator it = map.begin();
	for (; it != map.end(); it++)
	{
		if (it->second.getAccountNumber() == accountId) {
			std::cout << it->second << std::endl;
		}
	}
	file.pauseExecution();
}

void listAllAccounts() {

	std::multimap<int, Account>* mapPointer;
	File<Account> file("Accounts.dat");

	std::multimap<int, Account> map;
	mapPointer = &map;
	try {
		file.putIntoMap(mapPointer);
	}
	catch (const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}

	std::multimap<int, Account>::iterator it = map.begin();
	std::cout << map.size() << std::endl;

	for (; it != map.end(); it++)
	{
		std::cout << it->second << std::endl;
	}
	file.pauseExecution();
}


void updateAccount() {
	/*
	Account account{ 0, 0, "default", "default", 0.0};
	File<Account> file("Accounts.dat");
	std::multimap<int, Account> mapTest;
	int accountId{ 0 };
	int id{0};
	std::cout << ("Introduza o numero da conta a atualizar:\n");
	std::cin.ignore();
	std::cin >> accountId;
	
	mapTest = file.putIntoMapFiltered(account, accountId);

	std::multimap<int, Account>::iterator it = mapTest.begin();
	
	for (; it != mapTest.end(); it++)

	{
		if (it->second.getAccountNumber() == accountId) {
			id=it->second.getId();
		}

	}
	mapTest.clear();
	file.readRecord(account, id);
	if (!file.exists(account, id)) {
		std::string lastName;
		std::string firstName;
		double balance;

		std::cout << "Enter first Name, Last Name, Balance\n? ";
		std::cin >> std::setw(15) >> firstName;
		std::cin >> std::setw(10) >> lastName;
		std::cin >> balance;

		account.setFirstName(firstName);
		account.setLastName(lastName);
		account.setId(id);

		file.createRecord(account, id);
	}
	else {
		std::cerr << "Registo #" << id
			<< " ja contem informacao." << std::endl;
	}

	file.closeFile();
	*/
}


void deactivateAccount() {

	Account account;
	Account accountToChange;
	File<Account> file("Accounts.dat");

	std::multimap<int, Account>* mapPointer;
	std::multimap<int, Account> map;
	mapPointer = &map;

	int accountId{ 0 };
	int id{ 0 };
	std::cout << ("Insert the number of the account to deactivate:\n");
	std::cin.ignore();
	std::cin >> accountId;

	file.putIntoMap(mapPointer);

	std::multimap<int, Account>::iterator it = map.begin();
	for (; it != map.end(); it++)
	{
		if (it->second.getAccountNumber() == accountId) {
			accountToChange = it->second;
		}
	}
	map.clear();
	file.readRecord(account, accountToChange.getId());
	accountToChange.setState(false);
	file.createRecord(accountToChange, accountToChange.getId());

	file.closeFile();
	file.pauseExecution();
}



void deleteAccount() {

	/*
	Account account{ 0, 0, "default", "default", 0.0, "" };
	File<Account> file("Accounts.dat");
	std::cout << ("Introduza o id do registo a eliminar:\n");
	int id{ file.getMainId() };

	file.readRecord(account, id);

	if (account.getId() != 0) {
		Account blankAccount;
		file.deleteRecord(blankAccount, id);
		std::cout << "Registo #" << id << " eliminado.\n";
	}
	else {
		std::cerr << "Registo #" << id << " esta vazio.\n";
	}
	*/
}

void exportFile() {
	
	File<Account> file("Accounts.dat");
	Account newAccount;
	std::string fileName{ "" };
	std::cout << "Type the file name .txt :" << std::endl;
	std::cin >> fileName;
	file.exportToFile(newAccount, fileName);

}
