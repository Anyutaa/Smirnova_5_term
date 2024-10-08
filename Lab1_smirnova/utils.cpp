#include "pch.h"
#include "utils.h"


const int daysInMonth[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

bool inputDate(int& year, int& month, int& day) {
	while (true) {
		cout << "¬ведите год: ";
		year = GetCorrect(1, 9999);
		cout << "¬ведите мес€ц: ";
		month = GetCorrect(1, 12);
		cout << "¬ведите день: ";
		day = GetCorrect(1, 31);

		if (month == 2 && (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0))) {
			if (day <= 29) {
				return true;
			}
		}
		else if (day <= daysInMonth[month - 1]) {
			return true;
		}

		cout << "Ќеверна€ дата, попробуйте еще раз." << endl;
	}
}