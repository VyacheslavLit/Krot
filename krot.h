#pragma once
#include <iostream>
#include <Windows.h>
#include <fstream>
#include <string>
#include <vector>


struct pos
{
	pos() {}
	pos(int x, int y):pos_x(x), pos_y(y)
	{}
	int pos_x = 0;//x, y позици€ объекта на карте
	int pos_y = 0;
	bool occupancy = false;//зан€тость €чейки, используетс€ дл€ точек назначени€
};

class Krot
{
	/*
	count_blok количество блоков на карте
	значение беретс€ из файла
	изход€ из этого значени€ выдел€етс€ пам€ть дл€ координат блоков (blok) и точек назначени€ (destination_point) (их количество должно быть равным)
	*/
	int count_block;
	std::vector <pos> block;// = new pos[count_blok];
	std::vector <pos> destination_point;// = new pos[count_blok];

	pos pos_krot; //позици€ крота
	int krot_map[10][10]{ 0 };
	bool completing_the_map();
public:
	void creating_map();//создание карты
	void save_map();//запись карты в файл
	bool load_map();//считывание исходных данных из файла
	void go_gaem();//начало игры

};