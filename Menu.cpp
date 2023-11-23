#include "Menu.h"
#include <Windows.h>
#include <iostream>
#include <string>
#include <cstdio>
#include <conio.h>

//#include <ctype.h>

void menu()
{
		system("cls");
		std::cout << "   ----- Меню крота -----\n";
		std::cout << "1. создание карты.\n";
		std::cout << "2. запись карты в файл.\n";
		std::cout << "3. считывание карты из файла.\n";
		std::cout << "4. игра в крота.\n";
		std::cout << "5. Показатькарту.\n";
		std::cout << "0. Выход из игры.\n";
		std::cout << std::endl << "Выберите необходимый раздел: ";
}


void tmp()
{
	//for (int i = 0; i < 256; i++)
//{
//	std::cout << i << "   "<<(char)i << std::endl;
//}
	std::string i;
	int j;
	while (true)
	{
		i=_getch();
		//std::cin.get();
		j = 0;
		for (int p = 0; p < i.length(); p++)
		{
			j = j * 256 + i[p];
		}
		std::cout << i << "  " << j << std::endl;
	}

}