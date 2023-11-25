#include <iostream>
#include <windows.h>
#include "krot.h"
#include "Menu.h"


int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    Krot krot;
	//tmp();
	while (true)
	{
		menu();
		std::string choice;
		std::cin >> choice;
		if (std::cin.fail())
		{
			std::cin.clear();
			std::cin.ignore(32767, '\n');
			std::cout << "Выбор не определен, повторите попытку.\n";
			system("pause");
			continue;
		}
		if (choice[0] == '1') krot.creating_map();
		if (choice[0] == '2') krot.save_map();
		if (choice[0] == '3') krot.load_map();
		if (choice[0] == '4') krot.go_game();
		if (choice[0] == '5')
		{
			system("cls");
			krot.print_map();
			system("pause");
		}
		if (choice[0] == '0') break;

	}

	return 0;
}
