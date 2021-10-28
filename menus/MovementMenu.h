#pragma once

#include "./menus/BaseMenu.h"
#include "./models/Movement.h"
#include "MovementManagement.h"


class MovementMenu : public BaseMenu {

private:


public:

	MovementMenu(BaseMenu* baseMenu) : BaseMenu(baseMenu) {}

	~MovementMenu() {}

	void load() override {
		int choice{ 0 };
		std::cin >> choice;
		switch (choice) {
		case 1: {
			listMovements();
			reload();
		}break;

		case 2: {
			std::string movType = "DEP";
			transactionMov(movType);
			reload();
		}break;
		case 3: {
			std::string movType = "LEV";
			transactionMov(movType);
			reload();
		}break;
		case 4: {
			transferMov();
			reload();
		}break;
		case 5: {
			listAllMovements();
			reload();
		}break;
		case 0: {
			reloadParent();
		}break;
		}
	}

	void printOptions() override {
		std::cout << "...:: ACCOUNT MANAGER ::..." << std::endl;
		std::cout << std::endl;
		std::cout << "...:: MOVEMENTS AND TRANSACTIONS ::..." << std::endl;
		std::cout << std::endl;
		std::cout << "Please choose one of the following options: " << std::endl;
		std::cout << std::endl;
		std::cout << "1. List Account Transactions" << std::endl;
		std::cout << "2. Deposit" << std::endl;
		std::cout << "3. Withraw" << std::endl;
		std::cout << "4. Transfer" << std::endl;
		std::cout << "0. Exit" << std::endl;

	}
};