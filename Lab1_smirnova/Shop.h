#pragma once
#include <string>
#include "Product.h"
#include <vector>
using namespace std;

class Shop
{
	vector < Product* > shop;
public:
	~Shop();
	void Add_product();
	void OutputProduct();
	void Writing_to_file_product();
	void Read_from_file_product();
	void Delete_product();
};