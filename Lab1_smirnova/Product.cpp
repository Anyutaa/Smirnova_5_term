#include "pch.h"
#include "Product.h"
#include "utils.h"

void Product::Input (istream& in)
{
	cout << "Название продукта:";
	in.ignore();
	getline(cin, name_product);
	cerr << name_product << endl;
	cout << "Цена продукта";
	price = GetCorrect(1.0, 21000.0);
	int manufactureYear, manufactureMonth, manufactureDay;
	int validUntilYear, validUntilMonth, validUntilDay;

	while (true) {
		cout << "Дата изготовления продукта (yyyy mm dd):" << endl;
		if (inputDate(manufactureYear, manufactureMonth, manufactureDay)) {
			manufacture_year = manufactureYear;
			manufacture_month = manufactureMonth;
			manufacture_day = manufactureDay;
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
			valid_until_year = validUntilYear;
			valid_until_month = validUntilMonth;
			valid_until_day = validUntilDay;
			break;
		}
		else {
			cout << "Неверная дата, попробуйте еще раз." << endl;
		}
	}

	cout << "Количество продукта:";
	quantity_of_product = GetCorrect(1, 1000);
}


void Product::Output(ostream& out)
{
	if ((name_product) == "None")
	{
		out << "У вас нет продуктов" << endl;
		return ;
	}
	cout << "\n";
	out << "\nНазвание продукта: " << name_product
		<< "\nЦена продукта: " << price
		<< "\nДата изготовления: " << manufacture_year << "-" << manufacture_month << "-" << manufacture_day
		<< "\nгоден доl: " << valid_until_year << "-" << valid_until_month << "-" << valid_until_day
		<< "\nКоличество: " << quantity_of_product
		<< "\nЕсть ли в наличии: " << availability ;
	return ;
}



BOOST_CLASS_EXPORT(Product)
