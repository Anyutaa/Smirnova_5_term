#pragma once
#include "pch.h"

using namespace std;

template <typename T>
T GetCorrect(T min, T max)
{
	cout << " (" << min << "-" << max << "):";
	T x;
	while ((cin >> x).fail() || cin.peek() != '\n' || x<min || x>max)
	{
		cerr << x << endl;
		cin.clear();
		cin.ignore(1000, '\n');
		cout << "Type number (" << min << "-" << max << "):";
	}
	cerr << x << endl;
	return x;
}

bool inputDate(int& year, int& month, int& day);