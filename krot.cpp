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

bool Krot::reading_file_data(std::string file_name)
{
	std::ifstream in_file(file_name);
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