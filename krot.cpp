#include "krot.h"
#include <conio.h>


	/*
	1-����
	2-����� ����������
	3-����� ���������� ������� ������
	8-����� ���������� ������� ������
	9-����
	0-������ ������
	*/
bool Krot::completing_the_map()//�������������� ����� ������ �� ������� ������, ����� � ����� ����������
{

	for (int i = 0; i < 10; i++) for (int j = 0; j < 10; j++) krot_map[i][j] = 0;//��������� �����
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
	for (int i = 0; i < count_block; i++)
	{
		if (krot_map[block[i].pos_x][block[i].pos_y]==1|| krot_map[block[i].pos_x][block[i].pos_y] == 3)//�������� �� ��������� ������
		{
			std::cout << std::endl << "�������� ��������, ����� ����������.\n";
			for (int i = 0; i < 10; i++) for (int j = 0; j < 10; j++) krot_map[i][j] = 0;//��������� �����
			return false;
		}
		if (krot_map[block[i].pos_x][block[i].pos_y] == 2)//�������� �� ��������� ������ ������ ����������
		{
			krot_map[block[i].pos_x][block[i].pos_y] = 3;
			continue;
		}
		krot_map[block[i].pos_x][block[i].pos_y] = 1;
	}
	//������� ����� �� �����
	if (krot_map[pos_krot.pos_x][pos_krot.pos_y]==1|| krot_map[pos_krot.pos_x][pos_krot.pos_y] == 3)//�������� �� ��������� ������
	{
		std::cout << std::endl << "�������� ��������, ����� ����������.\n";
		for (int i = 0; i < 10; i++) for (int j = 0; j < 10; j++) krot_map[i][j] = 0;//��������� �����
		return false;
	}
	krot_map[pos_krot.pos_x][pos_krot.pos_y] = 9;
	return true;
}
void Krot::input_error()
{
	std::cin.clear();
	std::cin.ignore(32767, '\n');
	std::cout << "����� �� ���������. ���������� �������.\n";
	system("pause");
}
void Krot::distination_to(int x, int y)//��������� �������� �����
{
	if (pos_krot.pos_x + x < 0 || pos_krot.pos_x + x > 9 || pos_krot.pos_y + y > 9 || pos_krot.pos_y + y < 0) return;//��������� �������� ������ �� �������
	if (krot_map[pos_krot.pos_x + x][pos_krot.pos_y + y] == 0|| krot_map[pos_krot.pos_x + x][pos_krot.pos_y + y] == 2)//��������� �������� �������� �� ������ ������
	{
		pos_krot.pos_x += x;
		pos_krot.pos_y += y;
		completing_the_map();
		return;
	}
	if (krot_map[pos_krot.pos_x + x][pos_krot.pos_y + y] == 1 || krot_map[pos_krot.pos_x + x][pos_krot.pos_y + y] == 3)//��������� �������� ����� ������ ����
	{
		if (pos_krot.pos_x + 2 * x < 0 || pos_krot.pos_x + 2 * x > 9 || pos_krot.pos_y + 2 * y > 9 || pos_krot.pos_y + 2 * y < 0) return;//��������� �������� �� ������ �������
		if (krot_map[pos_krot.pos_x + 2 * x][pos_krot.pos_y + 2 * y] == 1|| krot_map[pos_krot.pos_x + 2 * x][pos_krot.pos_y + 2 * y] == 3) return;//��������� �������� �� ������ - ����
	
		pos_krot.pos_x += x;//����� ������� �����
		pos_krot.pos_y += y;

		for (int i = 0; i < count_block; i++)//����� ������� ����� � ����� ��� �������
		{
			if (block[i].pos_x == (pos_krot.pos_x) && block[i].pos_y == (pos_krot.pos_y))//���� ������ ����
			{
				block[i].pos_x += x;
				block[i].pos_y += y;
				if (krot_map[block[i].pos_x][block[i].pos_y] == 2)block[i].occupancy = true;
				else block[i].occupancy = false;
				break;
			}
		}

		completing_the_map();
		return;
	}

}
bool Krot::the_end()
{
	for (int i = 0; i < count_block; i++)//��������, ��� ��� ����� �� ����� ����������
	{
		if (!block[i].occupancy)return false;
	}
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
			if (krot_map[j][i] == 0) std::cout << "  ";//������ ������
			if (krot_map[j][i] == 9) std::cout << " "<<(char)164;//����
			if (krot_map[j][i] == 1) std::cout << " " << (char)35;//����
			if (krot_map[j][i] == 2) std::cout << " " << (char)149;//����
			if (krot_map[j][i] == 3) std::cout << " " << (char)169;//������� ����
		}
		std::cout << "|\n";
	}
	std::cout << "O--------------------O\n";
}
void Krot::creating_map()//�������� �����
{
	std::string choice;
	int x, y, x1, y1;
	while (true)
	{
		system("cls");
		print_map();
		std::cout << "\n\n\n����� �������� ������� ��������: \n";
		std::cout << "1. ������� ���������� �����.\n";
		std::cout << "2. ������� ���������� ����� � ����� ����.\n";
		std::cout << "0. ����� � ���������� ����.\n";
		std::cin >> choice;
		if (std::cin.fail())
		{
			input_error();
			continue;
		}
		if (choice[0] == '1')
		{
			std::cout << "���������� ����� �� ��� �: ";
			std::cin >> x;
			if (std::cin.fail())
			{
				input_error();
				continue;
			}
			std::cout << "���������� ����� �� ��� y: ";
			std::cin >> y;
			if (std::cin.fail())
			{
				input_error();
				continue;
			}
			if (x < 1 || x>10 || y < 1 || y>10)
			{
				std::cout << "���������� ��� �����. ��������� �����.\n";
				system("pause");
				continue;
			}
			if (krot_map[x-1][y-1] != 0)
			{
				std::cout << "\n������ ������� ������. ��������� �����.\n";
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
			std::cout << "���������� ����� �� ��� �: ";
			std::cin >> x;
			if (std::cin.fail())
			{
				input_error();
				continue;
			}
			std::cout << "���������� ����� �� ��� y: ";
			std::cin >> y;
			if (std::cin.fail())
			{
				input_error();
				continue;
			}
			std::cout << "���������� ����� ���������� �� ��� �: ";
			std::cin >> x1;
			if (std::cin.fail())
			{
				input_error();
				continue;
			}
			std::cout << "���������� ����� ���������� �� ��� y: ";
			std::cin >> y1;
			if (std::cin.fail())
			{
				input_error();
				continue;
			}

			if (x < 1 || x>10 || y < 1 || y>10||x1 < 1 || x1>10 || y1 < 1 || y1>10)
			{
				std::cout << "���������� ��� �����. ��������� �����.\n";
				system("pause");
				continue;
			}
			if (krot_map[x-1][y-1] != 0|| krot_map[x1-1][y1-1] )
			{
				std::cout << "\n���� �� ������� ������. ��������� �����.\n";
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
void Krot::save_map()//������ ����� � ����
{
	std::string file_name;
	system("cls");
	std::cout << "������� �������� ����� ��� ������: ";
	std::cin >> file_name;
	if (std::cin.fail())
	{
		input_error();
		return;
	}
	file_name += ".map";
	std::ofstream in_file(file_name);
	if (in_file.bad())
	{
		std::cout << "\n������ �������� ����� ��� ������. ����� � ���������� ����.\n";
		system("pause");
		return;
	}
	//���������� ���������� ������
	in_file << count_block << '\n';
	//���������� ���������� ������
	for (int i = 0; i < count_block; i++)
	{
		in_file << block[i].pos_x << '\n';
		in_file << block[i].pos_y << '\n';
	}
	//���������� ���������� ����� ����������
	for (int i = 0; i < count_block; i++)
	{
		in_file << destination_point[i].pos_x << '\n';
		in_file << destination_point[i].pos_y << '\n';
	}
	//���������� ���������� �����
	in_file << pos_krot.pos_x << '\n';
	in_file << pos_krot.pos_y << '\n';
}
bool Krot::load_map()
{
	std::string file_name;
	system("cls");
	std::cout << "������� �������� ����� ��� ����������: ";
	std::cin >> file_name;
	if (std::cin.fail())
	{
		input_error();
		return false;
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
		return false;
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
void Krot::go_game()//������ ����
{
	char distination;//���������� ���������� �����������
	while (true)
	{
		system("cls");
		print_map();
		if (the_end())//�������� �� ����� ����
		{
			std::cout << "���� ��������!!! �� �������!!!\n";
			system("pause");
			return;
		}
		std::cout << "\n������� ����������� ��������.\nS - ������ ��������.\n0 - ����� ��� ����������.\n";
		distination = _getch();
		if (distination == 72) distination_to(0,-1);
		if (distination == 80) distination_to(0,1);
		if (distination == 75) distination_to(-1,0);
		if (distination == 77) distination_to(1,0);
		if (distination == 's'|| distination == 'S') save_map();
		if (distination == '0') break;
	}
}

