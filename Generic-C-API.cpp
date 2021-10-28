
#include "./menus/BaseMenu.h"
#include "./menus/MainMenu.h"
#include "./datasources/File.h"
#include "./models/Account.h"




int main()
{
		MainMenu mainMenu = MainMenu();
		mainMenu.reload();
		return 0;
}

