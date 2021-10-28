#pragma once
#include <iostream>

class BaseMenu {

private:

	BaseMenu *parent;

public:

	BaseMenu() = default;						

	BaseMenu(BaseMenu *parent) {				
		this->parent = parent;					
	}

	virtual void printOptions() {};

	virtual void load() {};

	void clear() {
		std::cout << std::string(50, '\n');
	};

	void reload() {
		this->clear();
		this->printOptions();
		this->load();
	}

	void reloadParent() {
		this->parent->clear();
		this->parent->printOptions();
		this->parent->load();
		this->~BaseMenu();
	}

	void pauseExecution() {
		std::cout << "Press [Enter] to continue . . .";
		std::cin.ignore();
		std::cin.get();
	}
};