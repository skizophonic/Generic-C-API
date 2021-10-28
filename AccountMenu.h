#pragma once

#include "BaseMenu.h"
#include "Account.h"
#include "AccountManagement.h"


class AccountMenu : public BaseMenu {

private:

	
public:

	AccountMenu(BaseMenu* baseMenu) : BaseMenu(baseMenu) {}

	~AccountMenu() {}

	void load() override {
		int choice{ 0 };
		std::cin >> choice;
		switch (choice) {
		case 1: {
			insertAccount();
			reload();
		}break;

		case 2: {
			listAccount();
			reload();
		}break;

		case 3: {
			listAllAccounts();
			reload();
		}break;

		case 4: {
			deactivateAccount();
			reload();
		}break;

		case 5: {
			exportFile();
			reload();
		}break;

		case 0: {
			reloadParent();
		}break;
		}
	}

	void printOptions() override {
		std::cout << "...:: WELCOME TO ACCOUNT MANAGER ::..." << std::endl;
		std::cout << std::endl;
		std::cout << "...:: ACCOUNTS ::..." << std::endl;
		std::cout << std::endl;
		std::cout << "Please choose one of the following options: " << std::endl;
		std::cout << std::endl;
		std::cout << "1. Create a new account" << std::endl;
		std::cout << "2. Consult an account" << std::endl;
		std::cout << "3. List all accounts" << std::endl;
		std::cout << "4. Deactivate an account" << std::endl;
		std::cout << "5. Export to file" << std::endl;
		std::cout << "0. Exit" << std::endl;
	}
};