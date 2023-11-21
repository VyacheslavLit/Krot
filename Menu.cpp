#include "Menu.h"
#include <Windows.h>
#include <iostream>

void menu()
{
		system("cls");
		std::cout << "   ----- Меню крота -----\n";
		std::cout << "1. создание карты.\n";
		std::cout << "2. запись карты в файл.\n";
		std::cout << "3. считывание карты из файла.\n";
		std::cout << "4. игра в крота.\n";
		std::cout << "0. Выход из игры.\n";
		std::cout << std::endl << "Выберите необходимый раздел: ";
}