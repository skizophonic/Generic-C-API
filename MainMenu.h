#pragma once

#include "BaseMenu.h"
#include "AccountMenu.h"
#include "MovementMenu.h"


class MainMenu : public BaseMenu {

private:

	AccountMenu* accountMenu;
	MovementMenu* movementMenu;

public:

	MainMenu() {}

	~MainMenu() {}

	void load() override {
		int choice{ 0 };
		std::cin >> choice;
		do {

			switch (choice) {
			case 1: {
				accountMenu = new AccountMenu(this);
				accountMenu->reload();
			}break;
			case 2: {
				movementMenu = new MovementMenu(this);
				movementMenu->reload();
			}break;
			case 3: {

			}break;

			case 0: {

				exit(1);
			}break;
			}

		} while (choice != 0);
	}

	void printOptions() override {
		std::cout << "...:: WELCOME TO ACCOUNT MANAGER ::..." << std::endl;
		std::cout << std::endl;
		std::cout << "Please choose one of the following options: " << std::endl;
		std::cout << std::endl;
		std::cout << "1. Account Management" << std::endl;
		std::cout << "2. Movement Management" << std::endl;
		std::cout << "3. File Management" << std::endl;
		std::cout << "0. Exit" << std::endl;

	}
};