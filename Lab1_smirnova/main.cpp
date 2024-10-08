#include "pch.h"
#include "Product.h"
#include "Shop.h"
#include "utils.h"

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
			<< "\n2. Добавить онлайн продукт"
			<< "\n3. Посмотреть все продукты"
			<< "\n4. Удалить все продукты"
			<< "\n5. Записать в файл"
			<< "\n6. Прочитать из файла"
			<< "\n0. Выход"
			<< "\nВыберите действие ";
		int vibor = -1;
		vibor = GetCorrect(0, 6);
		switch (vibor)
		{
		case 1:
		{
			myshop.Add_product();
			break;
		}
		case 2:
		{
			myshop.Add_online_product();
			break;
		}
		case 3:
		{
			cout << "3. Посмотреть все продукты " << endl;
			myshop.OutputProduct();
			break;
		}
		case 4:
		{
			cout << "4. Удалить все продукты" << endl;
			myshop.Delete_product();
			break;
		}
		case 5:
		{
			cout << "5. Записать в файл" << endl;
			myshop.Writing_to_file_product();
			break;
		}
		case 6:
		{
			cout << "6. Прочитать из файла" << endl;
			myshop.Read_from_file_product();
			break;
		}

		case 0:
		{
			cout << "0. Выход" << endl;
			return 0;
		}
		}
	}
	return 0;
}