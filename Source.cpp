#include <iostream>
#include <fstream>
#include <windows.h>
#include <string>

int Choose(bool arr[]);

void Fill(std::ofstream& txt, bool arr[], int choose, std::string name);

void Close(std::ofstream& txt);

void Start();

int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	Start();
	return 0;
}

int Choose( bool arr[])
{

	int choose;
	std::cout << "В какой файл записать данные?" << std::endl << "1 - Название товара;\n 2 - Количество;\n 3 - Цена " << std::endl << " 0 - выход\n";
	std::cin >> choose;
	std::cin.ignore(32000, '\n');
	while (choose < 0 || choose>3) {
		std::cerr << "Error\n";
		std::cin >> choose;
	}

	if (choose == 1) {
		std::ofstream name;
		Fill(name, arr, choose, "name.txt");
	}
	else if (choose == 2) {
		std::ofstream count;
		Fill(count, arr, choose, "count.txt");

	}

	else if (choose == 3) {
		std::ofstream price;
		Fill(price, arr, choose, "price.txt");

	}
	else {
		return 0;

	}

}

void Fill(std::ofstream& txt, bool arr[], int choose, std::string name)
{
	int data;
	std::string data_for_file;


	if (arr[choose - 1] == true) {
		std::cout << "В документе есть данные, перезаполнить или продолжать заполнять?\n 1 - перезаполнить;\n 2 - продолжить\n";
		std::cin >> data;
		std::cin.ignore(32000, '\n');
		while (data < 1 || data>2) {
			std::cerr << "Error\n";
			std::cin >> data;
			std::cin.ignore(32000, '\n');
		}
		if (data == 1) {
			txt.open(name);
			std::cout << "Вводите данные\n";
			std::getline(std::cin, data_for_file);
			txt << data_for_file;

		}
		else {
			txt.open(name, txt.app);
			std::cout << "Вводите данные\n";
			std::getline(std::cin, data_for_file);
			txt << "\n" + data_for_file;

		}


	}
	else {
		txt.open(name);
		if (!txt.is_open()) {
			std::cerr << "error\n";
		}
		else {

			std::cout << "Вводите данные\n";
			std::getline(std::cin, data_for_file);
			txt << data_for_file;
		}



	}
	arr[choose - 1] = true;
	Close(txt);
	system("cls");
	Choose(arr);
}

void Close(std::ofstream& txt)
{
	txt.close();
}

void Start()
{
	const int SIZE = 3;
	bool data[SIZE]{ false, false, false };
	Choose(data);

}
