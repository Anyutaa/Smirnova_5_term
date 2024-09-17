#include "Product.h"
#include <iostream> 
#include <fstream>
#include <string>
#include "utils.h"

using namespace std;

const int daysInMonth[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

bool inputDate(int& year, int& month, int& day) {
	while (true) {
		cout << "Введите год: ";
		year = GetCorrect(1, 9999);
		cout << "Введите месяц: ";
		month = GetCorrect(1, 12);
		cout << "Введите день: ";
		day = GetCorrect(1, 31);

		if (month == 2 && (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0))) {
			if (day <= 29) {
				return true;
			}
		}
		else if (day <= daysInMonth[month - 1]) {
			return true;
		}

		cout << "Неверная дата, попробуйте еще раз." << endl;
	}
}


istream& operator >> (istream& in, Product& product)
{
	cout << "Название продукта:";
	cin.ignore();
	getline(cin, product.name_product);
	cerr << product.name_product << endl;
	cout << "Цена продукта (1.0, 21000.0):";
	product.price = GetCorrect(1.0, 21000.0);
	int manufactureYear, manufactureMonth, manufactureDay;
	int validUntilYear, validUntilMonth, validUntilDay;

	while (true) {
		cout << "Дата изготовления продукта (yyyy mm dd):" << endl;
		if (inputDate(manufactureYear, manufactureMonth, manufactureDay)) {
			product.manufacture_year = manufactureYear;
			product.manufacture_month = manufactureMonth;
			product.manufacture_day = manufactureDay;
			break;
		}
		else {
			cout << "Неверная дата, попробуйте еще раз." << endl;
		}
	}

	while (true) {
		cout << "Годен до (yyyy mm dd):" << endl;
		if (inputDate(validUntilYear, validUntilMonth, validUntilDay)) {
			if (manufactureYear > validUntilYear ||
				(manufactureYear == validUntilYear && manufactureMonth > validUntilMonth) ||
				(manufactureYear == validUntilYear && manufactureMonth == validUntilMonth && manufactureDay > validUntilDay)) {
				cout << "Дата производства не может быть позже срока годности!" << endl;
				continue;
			}
			product.valid_until_year = validUntilYear;
			product.valid_until_month = validUntilMonth;
			product.valid_until_day = validUntilDay;
			break;
		}
		else {
			cout << "Неверная дата, попробуйте еще раз." << endl;
		}
	}

	cout << "Количество продукта (1.0, 1000.0):";
	product.quantity_of_product = GetCorrect(1, 1000);
	return in;
}

ostream& operator << (ostream& out, const Product& product)
{
	if ((product.name_product) == "None")
	{
		out << "У вас нет продуктов" << endl;
		return out;
	}
	out << "\nНазвание продукта: " << product.name_product
		<< "\nЦена продукта: " << product.price
		<< "\nДата изготовления: " << product.manufacture_year << "-" << product.manufacture_month << "-" << product.manufacture_day
		<< "\nгоден доl: " << product.valid_until_year << "-" << product.valid_until_month << "-" << product.valid_until_day
		<< "\nКоличество: " << product.quantity_of_product
		<< "\nЕсть ли в наличии: " << product.availability << endl;
	return out;
}
ifstream& operator >> (ifstream& fin, Product& pr)
{
	getline(fin, pr.name_product);
	fin >> pr.price;
	fin >> pr.manufacture_year >> pr.manufacture_month >> pr.manufacture_day;
	fin >> pr.valid_until_year >> pr.valid_until_month >> pr.valid_until_day;
	fin >> pr.quantity_of_product;
	fin >> pr.availability;
	return fin;
}

ofstream& operator << (ofstream& fout, const Product& product) {

	if (product.name_product.empty())
	{
		cout << "У вас нет продуктов для сохранения" << endl;
	}
	else
	{
		fout << "Продукт:" << endl;
		fout << product.name_product << endl << product.price << endl << product.manufacture_year << " " << product.manufacture_month << " " << product.manufacture_day << endl
			<< product.valid_until_year << " " << product.valid_until_month << " " << product.valid_until_day << endl << product.quantity_of_product << endl << product.availability << endl;
	}
	return fout;
}
