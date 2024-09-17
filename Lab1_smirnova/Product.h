#pragma once
#include <string>
#include <unordered_map>
using namespace std;

class Product
{
	string name_product = "None";
	double price = 0;
	int manufacture_year=0;
	int manufacture_month=0;
	int manufacture_day=0;
	int valid_until_year=0;
	int valid_until_month=0;
	int valid_until_day=0;
	int quantity_of_product = 0;
	bool availability = 1;
public:
	friend istream& operator >> (istream& in, Product& product);
	friend ostream& operator << (ostream& out, const Product& product);
	friend ifstream& operator >> (ifstream& fin, Product& pr);
	friend ofstream& operator << (ofstream& fout, const Product& product);
};
