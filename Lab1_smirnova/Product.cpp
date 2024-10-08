#include "pch.h"
#include "Product.h"
#include "utils.h"

void Product::Input (istream& in)
{
	cout << "�������� ��������:";
	in.ignore();
	getline(cin, name_product);
	cerr << name_product << endl;
	cout << "���� ��������";
	price = GetCorrect(1.0, 21000.0);
	int manufactureYear, manufactureMonth, manufactureDay;
	int validUntilYear, validUntilMonth, validUntilDay;

	while (true) {
		cout << "���� ������������ �������� (yyyy mm dd):" << endl;
		if (inputDate(manufactureYear, manufactureMonth, manufactureDay)) {
			manufacture_year = manufactureYear;
			manufacture_month = manufactureMonth;
			manufacture_day = manufactureDay;
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
			valid_until_year = validUntilYear;
			valid_until_month = validUntilMonth;
			valid_until_day = validUntilDay;
			break;
		}
		else {
			cout << "�������� ����, ���������� ��� ���." << endl;
		}
	}

	cout << "���������� ��������:";
	quantity_of_product = GetCorrect(1, 1000);
}


void Product::Output(ostream& out)
{
	if ((name_product) == "None")
	{
		out << "� ��� ��� ���������" << endl;
		return ;
	}
	cout << "\n";
	out << "\n�������� ��������: " << name_product
		<< "\n���� ��������: " << price
		<< "\n���� ������������: " << manufacture_year << "-" << manufacture_month << "-" << manufacture_day
		<< "\n����� ��l: " << valid_until_year << "-" << valid_until_month << "-" << valid_until_day
		<< "\n����������: " << quantity_of_product
		<< "\n���� �� � �������: " << availability ;
	return ;
}



BOOST_CLASS_EXPORT(Product)
