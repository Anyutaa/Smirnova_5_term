#include <iostream> 
#include <fstream>
#include <string>
#include <vector>
#include <set>
#include <algorithm>
#include "Product.h"
#include "Shop.h"
#include "utils.h"
#include <windows.h>

using namespace std;



int main()
{
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);
	Shop myshop;
	while (true)
	{
		cout << "\nВыберите вариант из меню :"
			<< "\n1. Добавить продукт"
			<< "\n2. Посмотреть все продукты"
			<< "\n3. Удалить все продукты"
			<< "\n4. Записать в файл"
			<< "\n5. Прочитать из файла"
			<< "\n6. Выход"
			<< "\nВыберите действие ";
		int vibor = -1;
		vibor = GetCorrect(1, 6);
		switch (vibor)
		{
		case 1:
		{
			myshop.Add_product();
			break;
		}
		case 2:
		{
			cout << "2. Посмотреть все продукты " << endl;
			myshop.OutputProduct();
			break;
		}
		case 3:
		{
			cout << "3. Удалить все продукты" << endl;
			myshop.Delete_product();
			break;
		}
		case 4:
		{
			cout << "4. Записать в файл" << endl;
			myshop.Writing_to_file_product();
			break;
		}
		case 5:
		{
			cout << "5. Прочитать из файла" << endl;
			myshop.Read_from_file_product();
			break;
		}

		case 6:
		{
			cout << "6. Выход" << endl;
			return 0;
		}
		}
	}
	return 0;
}