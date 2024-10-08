#pragma once
#include "pch.h"
#include "Product.h"
#include "Online_product.h"

class Shop
{
	vector<shared_ptr<Product>> shop;
public:
	void Add_product();
	void Add_online_product();
	void OutputProduct();
	void Writing_to_file_product();
	void Read_from_file_product();
	void Delete_product();
	template<class Archive>
	void serialize(Archive& ar, const unsigned int version)
	{
		ar& Product;
	}
};

