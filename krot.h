#pragma once
#include <iostream>
#include <Windows.h>
#include <fstream>
#include <string>
#include <vector>


struct pos
{
	pos(int x, int y):pos_x(x), pos_y(y)
	{}
	int pos_x = 0;//x, y ������� ������� �� �����
	int pos_y = 0;
	bool occupancy = false;//��������� ������, ������������ ��� ����� ����������
};

class Krot
{
	/*
	count_blok ���������� ������ �� �����
	�������� ������� �� �����
	������ �� ����� �������� ���������� ������ ��� ��������� ������ (blok) � ����� ���������� (destination_point) (�� ���������� ������ ���� ������)
	*/
	int count_block;
	std::vector <pos> block;// = new pos[count_blok];
	std::vector <pos> destination_point;// = new pos[count_blok];

	pos pos_krot; //������� �����
	int krot_map[10][10]{ 0 };
	bool completing_the_map();
public:
	bool reading_file_data(std::string);//���������� �������� ������ �� �����
};