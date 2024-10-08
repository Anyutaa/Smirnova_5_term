#include "pch.h"
#include "Product.h"
#include "Shop.h"
#include "utils.h"

using namespace std;

int main()
{
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);
	Shop myshop;
	while (true)
	{
		cout << "\n�������� ������� �� ���� :"
			<< "\n1. �������� �������"
			<< "\n2. �������� ������ �������"
			<< "\n3. ���������� ��� ��������"
			<< "\n4. ������� ��� ��������"
			<< "\n5. �������� � ����"
			<< "\n6. ��������� �� �����"
			<< "\n0. �����"
			<< "\n�������� �������� ";
		int vibor = -1;
		vibor = GetCorrect(0, 6);
		switch (vibor)
		{
		case 1:
		{
			myshop.Add_product();
			break;
		}
		case 2:
		{
			myshop.Add_online_product();
			break;
		}
		case 3:
		{
			cout << "3. ���������� ��� �������� " << endl;
			myshop.OutputProduct();
			break;
		}
		case 4:
		{
			cout << "4. ������� ��� ��������" << endl;
			myshop.Delete_product();
			break;
		}
		case 5:
		{
			cout << "5. �������� � ����" << endl;
			myshop.Writing_to_file_product();
			break;
		}
		case 6:
		{
			cout << "6. ��������� �� �����" << endl;
			myshop.Read_from_file_product();
			break;
		}

		case 0:
		{
			cout << "0. �����" << endl;
			return 0;
		}
		}
	}
	return 0;
}