#include "krot.h"

bool Krot::completing_the_map()
{
	for (int i = 0; i < 10; i++) for (int j = 0; j < 10; j++) krot_map[i][j] = 0;//��������� �����
	//������� ����� �� �����
	for (int i = 0; i < count_block; i++)
	{
		if (krot_map[block[i].pos_x][block[i].pos_y])//�������� �� ��������� ������
		{
			std::cout << std::endl << "�������� ��������, ����� ����������.\n";
			for (int i = 0; i < 10; i++) for (int j = 0; j < 10; j++) krot_map[i][j] = 0;//��������� �����
			return false;
		}
		krot_map[block[i].pos_x][block[i].pos_y] = 1;
	}
	//������� ����� ���������� �� �����
	for (int i = 0; i < count_block; i++)
	{
		if (krot_map[destination_point[i].pos_x][destination_point[i].pos_y])//�������� �� ��������� ������
		{
			std::cout << std::endl << "�������� ��������, ����� ����������.\n";
			for (int i = 0; i < 10; i++) for (int j = 0; j < 10; j++) krot_map[i][j] = 0;//��������� �����
			return false;
		}
		krot_map[destination_point[i].pos_x][destination_point[i].pos_y] = 2;
	}
	//������� ����� �� �����
	if (krot_map[pos_krot.pos_x][pos_krot.pos_y])//�������� �� ��������� ������
	{
		std::cout << std::endl << "�������� ��������, ����� ����������.\n";
		for (int i = 0; i < 10; i++) for (int j = 0; j < 10; j++) krot_map[i][j] = 0;//��������� �����
		return false;
	}
	krot_map[pos_krot.pos_x][pos_krot.pos_y] = 9;
	return true;
}

void Krot::creating_map();//�������� �����
void Krot::save_map();//������ ����� � ����
bool Krot::load_map()
{
	std::string file_name;
	system("cls");
	std::cout << "������� �������� ����� ��� ����������: ";
	std::cin >> file_name;
	if (std::cin.fail())
	{
		std::cin.clear();
		std::cin.ignore(32767, '\n');
		std::cout << "\n������ �����. ����� � ���������� ����.\n";
		system("pause");
		return;
	}
	file_name += ".map";
	count_block = 0;
	block.clear();
	destination_point.clear();
	std::ifstream in_file(file_name);
	if (in_file.bad())
	{
		std::cout << "\n������ ����� �� ����������. ����� � ���������� ����.\n";
		system("pause");
		return;
	}
	if (!in_file)
	{
		std::cout << "������ ����� � ������ �� ������!\n";
		return false;
	}
	std::string input;
	//��������� ���������� ������
	in_file >> input;
	count_block = std::stoi(input);
	//�������� ���������� ������
	for (int i = 0; i < count_block; i++)
	{
		in_file >> input;
		int pos_x = std::stoi(input);
		in_file >> input;
		int pos_y = std::stoi(input);
		pos position(pos_x, pos_y);
		block.push_back(position);
	}
	//��������� ���������� ����� ����������
	for (int i = 0; i < count_block; i++)
	{
		in_file >> input;
		int pos_x = std::stoi(input);
		in_file >> input;
		int pos_y = std::stoi(input);
		pos position(pos_x, pos_y);
		destination_point.push_back(position);
	}
	//��������� ���������� �����
	in_file >> input;
	pos_krot.pos_x = std::stoi(input);
	in_file >> input;
	pos_krot.pos_y = std::stoi(input);
	if(!completing_the_map()) return false;
	return true;
}
void Krot::go_gaem();//������ ����