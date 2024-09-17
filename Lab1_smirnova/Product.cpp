#include "Product.h"
#include <iostream> 
#include <fstream>
#include <string>
#include "utils.h"

using namespace std;

const int daysInMonth[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

bool inputDate(int& year, int& month, int& day) {
	while (true) {
		cout << "������� ���: ";
		year = GetCorrect(1, 9999);
		cout << "������� �����: ";
		month = GetCorrect(1, 12);
		cout << "������� ����: ";
		day = GetCorrect(1, 31);

		if (month == 2 && (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0))) {
			if (day <= 29) {
				return true;
			}
		}
		else if (day <= daysInMonth[month - 1]) {
			return true;
		}

		cout << "�������� ����, ���������� ��� ���." << endl;
	}
}


istream& operator >> (istream& in, Product& product)
{
	cout << "�������� ��������:";
	cin.ignore();
	getline(cin, product.name_product);
	cerr << product.name_product << endl;
	cout << "���� �������� (1.0, 21000.0):";
	product.price = GetCorrect(1.0, 21000.0);
	int manufactureYear, manufactureMonth, manufactureDay;
	int validUntilYear, validUntilMonth, validUntilDay;

	while (true) {
		cout << "���� ������������ �������� (yyyy mm dd):" << endl;
		if (inputDate(manufactureYear, manufactureMonth, manufactureDay)) {
			product.manufacture_year = manufactureYear;
			product.manufacture_month = manufactureMonth;
			product.manufacture_day = manufactureDay;
			break;
		}
		else {
			cout << "�������� ����, ���������� ��� ���." << endl;
		}
	}

	while (true) {
		cout << "����� �� (yyyy mm dd):" << endl;
		if (inputDate(validUntilYear, validUntilMonth, validUntilDay)) {
			if (manufactureYear > validUntilYear ||
				(manufactureYear == validUntilYear && manufactureMonth > validUntilMonth) ||
				(manufactureYear == validUntilYear && manufactureMonth == validUntilMonth && manufactureDay > validUntilDay)) {
				cout << "���� ������������ �� ����� ���� ����� ����� ��������!" << endl;
				continue;
			}
			product.valid_until_year = validUntilYear;
			product.valid_until_month = validUntilMonth;
			product.valid_until_day = validUntilDay;
			break;
		}
		else {
			cout << "�������� ����, ���������� ��� ���." << endl;
		}
	}

	cout << "���������� �������� (1.0, 1000.0):";
	product.quantity_of_product = GetCorrect(1, 1000);
	return in;
}

ostream& operator << (ostream& out, const Product& product)
{
	if ((product.name_product) == "None")
	{
		out << "� ��� ��� ���������" << endl;
		return out;
	}
	out << "\n�������� ��������: " << product.name_product
		<< "\n���� ��������: " << product.price
		<< "\n���� ������������: " << product.manufacture_year << "-" << product.manufacture_month << "-" << product.manufacture_day
		<< "\n����� ��l: " << product.valid_until_year << "-" << product.valid_until_month << "-" << product.valid_until_day
		<< "\n����������: " << product.quantity_of_product
		<< "\n���� �� � �������: " << product.availability << endl;
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
		cout << "� ��� ��� ��������� ��� ����������" << endl;
	}
	else
	{
		fout << "�������:" << endl;
		fout << product.name_product << endl << product.price << endl << product.manufacture_year << " " << product.manufacture_month << " " << product.manufacture_day << endl
			<< product.valid_until_year << " " << product.valid_until_month << " " << product.valid_until_day << endl << product.quantity_of_product << endl << product.availability << endl;
	}
	return fout;
}
