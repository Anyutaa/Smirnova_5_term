#include "pch.h"
#include "Shop.h"

void Shop::Add_product() {
	shared_ptr<Product> pr = make_shared<Product>();
	cout << "1. Добавить продукт" << endl;
	pr -> Input(cin);
	shop.push_back(pr);
}

void Shop::Add_online_product() {
	shared_ptr<Online_product> pr_online = make_shared<Online_product>();
	cout << "2. Добавить онлайн продукт" << endl;
	pr_online->Input(cin);
	shop.push_back(pr_online);
}
void Shop::OutputProduct()
{
	if ((shop.size()) == 0)
	{
		cout << "У вас нет продуктов" << endl;
	}
	else
		for (const auto& x : shop)
			x->Output(cout);
	cout << "\n";
}
void Shop::Writing_to_file_product()
{
	if  (shop.empty())
	{
		cout << "Нет информации о продуктах " << endl;
		return;
	}
	else {
		cout << "Введите название файла: ";
		string filename;
		cin.ignore();
		getline(cin, filename);
		cerr << filename << endl;
		ofstream fout((filename + ".dat"), ofstream::binary);
		boost::archive::binary_oarchive ar(fout);
		ar << shop;
		
		cout << "Информация о продуктах записана " << endl;

		fout.close();
		/*}*/
	}
}
void Shop::Read_from_file_product()
{
	
	string filename;
	cout << "Введите название файла: ";
	cin.ignore();
	getline(cin, filename);
	cerr << filename << endl;
	ifstream fin(filename + ".dat", ofstream::binary);

	if (fin.is_open())
	{
		try{
			boost::archive::binary_iarchive ar(fin);
			ar >> shop;
		}
		catch (const exception& e) {
			cout << "Чтение прервано: " << e.what() << "." << endl;
			Delete_product();
			fin.close();
			return;
		}
	}
	else
	{
		cout << "Не удалось открыть файл" + filename + ".dat." << endl;
	}
	fin.close();
}
void Shop::Delete_product() 
{
	shop.clear();
	cout << "Все продукты удалены" << endl;
}