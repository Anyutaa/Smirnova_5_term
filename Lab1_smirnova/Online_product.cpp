#include "pch.h"
#include "Online_product.h"

BOOST_CLASS_EXPORT(Online_product)

void Online_product::Input(istream& in)
{
	Product::Input(cin);
	cout << "—сылка на продукт:";
	in.ignore();
	getline(cin, link);
	cerr << link << endl;
}

void Online_product::Output(ostream& out) 
{
	Product::Output(out);
	out << "\n—сылка на продукт: " << link ;
}
