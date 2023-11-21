#include "krot.h"

bool Krot::completing_the_map()
{
	for (int i = 0; i < 10; i++) for (int j = 0; j < 10; j++) krot_map[i][j] = 0;//обнуление карты
	//заносим блоки на карту
	for (int i = 0; i < count_block; i++)
	{
		if (krot_map[block[i].pos_x][block[i].pos_y])//проверка на занятость ячейки
		{
			std::cout << std::endl << "Конфликт объектов, карта обнуляется.\n";
			for (int i = 0; i < 10; i++) for (int j = 0; j < 10; j++) krot_map[i][j] = 0;//обнуление карты
			return false;
		}
		krot_map[block[i].pos_x][block[i].pos_y] = 1;
	}
	//заносим точки назначения на карту
	for (int i = 0; i < count_block; i++)
	{
		if (krot_map[destination_point[i].pos_x][destination_point[i].pos_y])//проверка на занятость ячейки
		{
			std::cout << std::endl << "Конфликт объектов, карта обнуляется.\n";
			for (int i = 0; i < 10; i++) for (int j = 0; j < 10; j++) krot_map[i][j] = 0;//обнуление карты
			return false;
		}
		krot_map[destination_point[i].pos_x][destination_point[i].pos_y] = 2;
	}
	//заносим крота на карту
	if (krot_map[pos_krot.pos_x][pos_krot.pos_y])//проверка на занятость ячейки
	{
		std::cout << std::endl << "Конфликт объектов, карта обнуляется.\n";
		for (int i = 0; i < 10; i++) for (int j = 0; j < 10; j++) krot_map[i][j] = 0;//обнуление карты
		return false;
	}
	krot_map[pos_krot.pos_x][pos_krot.pos_y] = 9;
	return true;
}
void Krot::print_map()
{
	std::cout << "O--------------------O\n";
	for (int i = 0; i < 10; ++i)
	{
		std::cout << "|";
		for (int j = 0; j < 10; ++j)
		{
			if (krot_map[j][i] == 0) std::cout << "  ";//пустая ячейка
			if (krot_map[j][i] == 9) std::cout << " "<<(char)164;//крот
			if (krot_map[j][i] == 1) std::cout << " " << (char)35;//блок
			if (krot_map[j][i] == 2) std::cout << " " << (char)149;//цель
			if (krot_map[j][i] == 3) std::cout << " " << (char)169;//занятая цель
		}
		std::cout << "|\n";
	}
	std::cout << "O--------------------O\n";
}
void Krot::input_error()
{
	std::cin.clear();
	std::cin.ignore(32767, '\n');
	std::cout << "Выбор не определен. Повторитее попытку.\n";
	system("pause");
}

void Krot::creating_map()//создание карты
{
	std::string choice;
	int x, y, x1, y1;
	while (true)
	{
		system("cls");
		print_map();
		std::cout << "\n\n\nКакую операцию желаете провести: \n";
		std::cout << "1. Указать координаты крота.\n";
		std::cout << "2. Указать координаты блока и точки цели.\n";
		std::cout << "0. Выход в предыдущее меню.\n";
		std::cin >> choice;
		if (std::cin.fail())
		{
			input_error();
			continue;
		}
		if (choice[0] == '1')
		{
			std::cout << "Координаты крота по оси х: ";
			std::cin >> x;
			if (std::cin.fail())
			{
				input_error();
				continue;
			}
			std::cout << "Координаты крота по оси y: ";
			std::cin >> y;
			if (std::cin.fail())
			{
				input_error();
				continue;
			}
			if (x < 1 || x>10 || y < 1 || y>10)
			{
				std::cout << "Координаты вне карты. повторите выбор.\n";
				system("pause");
				continue;
			}
			if (krot_map[x-1][y-1] != 0)
			{
				std::cout << "\nДанная позиция занята. Повторите выбор.\n";
				system("pause");
				continue;
			}
			pos_krot.pos_x = x-1;
			pos_krot.pos_y = y-1;
			completing_the_map();
			continue;
		}
		if (choice[0] == '2')
		{
			std::cout << "Координаты блока по оси х: ";
			std::cin >> x;
			if (std::cin.fail())
			{
				input_error();
				continue;
			}
			std::cout << "Координаты блока по оси y: ";
			std::cin >> y;
			if (std::cin.fail())
			{
				input_error();
				continue;
			}
			std::cout << "Координаты точки назначения по оси х: ";
			std::cin >> x1;
			if (std::cin.fail())
			{
				input_error();
				continue;
			}
			std::cout << "Координаты точки назначения по оси y: ";
			std::cin >> y1;
			if (std::cin.fail())
			{
				input_error();
				continue;
			}

			if (x < 1 || x>10 || y < 1 || y>10||x1 < 1 || x1>10 || y1 < 1 || y1>10)
			{
				std::cout << "Координаты вне карты. повторите выбор.\n";
				system("pause");
				continue;
			}
			if (krot_map[x-1][y-1] != 0|| krot_map[x1-1][y1-1] )
			{
				std::cout << "\nОдна из позиций занята. Повторите выбор.\n";
				system("pause");
				continue;
			}
			pos add_block(x-1, y-1);
			block.push_back(add_block);
			pos add_destination_point(x1-1, y1-1);
			destination_point.push_back(add_destination_point);
			count_block++;
			completing_the_map();
			continue;
		}
		if (choice[0] == '0') break;
	}
}
void Krot::save_map()//запись карты в файл
{

}
bool Krot::load_map()
{
	std::string file_name;
	system("cls");
	std::cout << "Введите название файла для считывания: ";
	std::cin >> file_name;
	if (std::cin.fail())
	{
		std::cin.clear();
		std::cin.ignore(32767, '\n');
		std::cout << "\nОшибка ввода. Выход в предыдущее меню.\n";
		system("pause");
		return false;
	}
	file_name += ".map";
	count_block = 0;
	block.clear();
	destination_point.clear();
	std::ifstream in_file(file_name);
	if (in_file.bad())
	{
		std::cout << "\nТакого файла не существует. Выход в предыдущее меню.\n";
		system("pause");
		return false;
	}
	if (!in_file)
	{
		std::cout << "Чтение файла с картой не удачно!\n";
		return false;
	}
	std::string input;
	//считываем количество блоков
	in_file >> input;
	count_block = std::stoi(input);
	//счмтывем координаты блоков
	for (int i = 0; i < count_block; i++)
	{
		in_file >> input;
		int pos_x = std::stoi(input);
		in_file >> input;
		int pos_y = std::stoi(input);
		pos position(pos_x, pos_y);
		block.push_back(position);
	}
	//считываем координаты точек назначения
	for (int i = 0; i < count_block; i++)
	{
		in_file >> input;
		int pos_x = std::stoi(input);
		in_file >> input;
		int pos_y = std::stoi(input);
		pos position(pos_x, pos_y);
		destination_point.push_back(position);
	}
	//считываем координаты крота
	in_file >> input;
	pos_krot.pos_x = std::stoi(input);
	in_file >> input;
	pos_krot.pos_y = std::stoi(input);
	if(!completing_the_map()) return false;
	return true;
}
void Krot::go_game()//начало игры
{

}