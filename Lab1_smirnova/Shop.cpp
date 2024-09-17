#include "Shop.h"
#include <iostream> 
#include <fstream>

void Shop::Add_product() {
	Product* pr = new Product();
	cout << "1. �������� �������" << endl;
	cin >> *pr;
	shop.push_back(pr);
}
void Shop::OutputProduct()
{
	if ((shop.size()) == 0)
	{
		cout << "� ��� ��� ���������" << endl;
	}
	else
		for (Product* x : shop)
			cout << *x << endl;
}
void Shop::Writing_to_file_product()
{
	if  (shop.empty())
	{
		cout << "��� ���������� � ��������� " << endl;
		return;
	}
	else {
		cout << "������� �������� �����: ";
		string filename;
		cin.ignore();
		getline(cin, filename);
		cerr << filename << endl;
		ofstream fout((filename + ".txt"), ios::trunc);

		if (fout.is_open())
		{
			for (Product* x : shop)
				fout << *x;
			cout << "���������� � ��������� �������� " << endl;

			fout.close();
		}
	}
}
void Shop::Read_from_file_product()
{
	ifstream fin;
	string filename;
	cout << "������� �������� �����: ";
	cin.ignore();
	getline(cin, filename);
	cerr << filename << endl;
	fin.open(filename + ".txt");
	if (!fin.is_open()) {
		cerr << "������ �������� ������." << endl;
		return;
	}
	Delete_product();
	if (fin)
	{
		string name_of_product = "none";
		bool foundProduct = false;
		while (getline(fin, name_of_product))
		{
			if (name_of_product == "�������:")
			{
				Product* pr = new Product();  
				fin >> *pr;
				shop.push_back(pr);
				foundProduct = true;
			}
		}
		if (!foundProduct)
		{
			cout << "��� ���������� � ��������" << endl;
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
		cout << "��� ��������� ��� ��������" << endl;
		return;
	}
	for (Product* p : shop) {
		delete p;
	}
	shop.clear();
	cout << "��� �������� �������" << endl;
}