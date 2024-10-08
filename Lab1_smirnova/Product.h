#pragma once
#include "pch.h"

class Product
{
	friend class boost::serialization::access;

protected:
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

	template<class Archive>
	void serialize(Archive& ar, const unsigned int version)
	{
		ar& name_product;
		ar& price;
		ar& manufacture_year;
		ar& manufacture_month;
		ar& manufacture_day;
		ar& valid_until_year;
		ar& valid_until_month;
		ar& valid_until_day;
		ar& quantity_of_product;
		ar& availability;
	}
public:
	virtual void Input(istream& in);
	virtual void Output(ostream& out);
	virtual ~Product() = default;
	
};

