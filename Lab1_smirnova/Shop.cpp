#include "Shop.h"
#include <iostream> 
#include <fstream>

void Shop::Add_product() {
	Product* pr = new Product();
	cout << "1. Добавить продукт" << endl;
	cin >> *pr;
	shop.push_back(pr);
}
void Shop::OutputProduct()
{
	if ((shop.size()) == 0)
	{
		cout << "У вас нет продуктов" << endl;
	}
	else
		for (Product* x : shop)
			cout << *x << endl;
}
void Shop::Writing_to_file_product()
{
	if  (shop.empty())
	{
		cout << "Нет информации о продуктах " << endl;
		return;
	}
	else {
		cout << "Введите название файла: ";
		string filename;
		cin.ignore();
		getline(cin, filename);
		cerr << filename << endl;
		ofstream fout((filename + ".txt"), ios::trunc);

		if (fout.is_open())
		{
			for (Product* x : shop)
				fout << *x;
			cout << "Информация о продуктах записана " << endl;

			fout.close();
		}
	}
}
void Shop::Read_from_file_product()
{
	ifstream fin;
	string filename;
	cout << "Введите название файла: ";
	cin.ignore();
	getline(cin, filename);
	cerr << filename << endl;
	fin.open(filename + ".txt");
	if (!fin.is_open()) {
		cerr << "Ошибка открытия файлов." << endl;
		return;
	}
	Delete_product();
	if (fin)
	{
		string name_of_product = "none";
		bool foundProduct = false;
		while (getline(fin, name_of_product))
		{
			if (name_of_product == "Продукт:")
			{
				Product* pr = new Product();  
				fin >> *pr;
				shop.push_back(pr);
				foundProduct = true;
			}
		}
		if (!foundProduct)
		{
			cout << "Нет информации о продукте" << endl;
		}
		else
			return OutputProduct();
	}
	fin.close();
}
Shop::~Shop() {
	Delete_product();
}

void Shop::Delete_product() 
{
	if (shop.empty()) {
		cout << "Нет продуктов для удаления" << endl;
		return;
	}
	for (Product* p : shop) {
		delete p;
	}
	shop.clear();
	cout << "Все продукты удалены" << endl;
}