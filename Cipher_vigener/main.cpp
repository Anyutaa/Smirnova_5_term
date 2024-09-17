#include <iostream>
#include <string>
#include <fstream>
#include <Windows.h>
#include <locale>
#include <cwctype>

using namespace std;

// Структура для хранения названий файлов и ключа
struct file_shifr {
    wstring inputfile, outputfile;
    wstring key;
};

// Проверка корректности ввода числа
template <typename T>
T correctnumber(T min, T max) {
    T x;
    while (((wcin >> x).fail()) || (wcin.peek() != L'\n') || (x < min) || (x > max)) {
        wcout << L"Ошибка! Введите корректное число: >= " << min << L" и <= " << max << endl;
        wcin.clear();
        wcin.ignore(INT_MAX, L'\n');
    }
    return x;
}

wchar_t VigenereShift(wchar_t ch, wchar_t key, bool encrypt = true) {
    bool isRussianUpper = (ch >= L'А' && ch <= L'Я');
    bool isRussianLower = (ch >= L'а' && ch <= L'я');
    bool isEnglishUpper = (ch >= L'A' && ch <= L'Z');
    bool isEnglishLower = (ch >= L'a' && ch <= L'z');

    int alphabetSize = 0;
    int chCode = 0;
    int keyCode = 0;
    int offset = 0;
    int newCode = 0;

    if (isRussianUpper || isRussianLower) {
        alphabetSize = 32;
        chCode = isRussianUpper ? ch - L'А' : ch - L'а';
        keyCode = (key >= L'А' && key <= L'Я') ? key - L'А' : key - L'а';
        offset = encrypt ? keyCode : -keyCode;
        newCode = (chCode + offset + alphabetSize) % alphabetSize;
        if (newCode < 0) {
            newCode += alphabetSize;
        }
        return isRussianUpper ? (newCode + L'А') : (newCode + L'а');
    }
    else if (isEnglishUpper || isEnglishLower) {
        alphabetSize = 26;
        chCode = isEnglishUpper ? ch - L'A' : ch - L'a';
        keyCode = (key >= L'A' && key <= L'Z') ? key - L'A' : key - L'a';
        offset = encrypt ? keyCode : -keyCode;
        newCode = (chCode + offset + alphabetSize) % alphabetSize;
        if (newCode < 0) {
            newCode += alphabetSize;
        }
        return isEnglishUpper ? (newCode + L'A') : (newCode + L'a');
    }
    else {
        return ch;  // Если символ не принадлежит алфавитам, возвращаем его без изменений
    }
}


// Функция шифрования и дешифрования
void Shifr(file_shifr& f, int x) {
    wchar_t symbol;
    int i = 0;

    wcout << L"\nВведите название файла для ввода (без .txt): " << endl;
    wcin >> f.inputfile;
    wcout << L"Введите название файла для вывода (без .txt): " << endl;
    wcin >> f.outputfile;
    wcout << L"Введите ключ для кодирования: " << endl;
    wcin >> f.key;

    wifstream in(f.inputfile + L".txt");  // Открытие входного файла
    wofstream out(f.outputfile + L".txt");  // Открытие выходного файла

    locale loc("ru_RU.UTF-8");
    in.imbue(loc);
    out.imbue(loc);

    if (!in.is_open() || !out.is_open()) {
        wcout << L"\nОшибка открытия файла!" << endl;
        return;
    }

    // Преобразование ключа в нижний регистр для упрощения вычислений
    for (wchar_t& c : f.key) {
        c = towlower(c);
    }

    // Процесс шифрования/дешифрования
    while (in.get(symbol)) {
        wchar_t k = f.key[i % f.key.size()];  // Символ ключа по модулю длины ключа
        symbol = VigenereShift(symbol, k, (x == 1));  // true для шифрования, false для дешифрования
        i++;

        out.put(symbol);  // Запись в выходной файл
    }

    wcout << (x == 1 ? L"\nТекст зашифрован" : L"\nТекст расшифрован") << endl;

    in.close();
    out.close();
}

int main() {
    setlocale(LC_ALL, "ru_RU.UTF-8");
    SetConsoleCP(65001);  // UTF-8 кодировка для ввода
    SetConsoleOutputCP(65001);  // UTF-8 кодировка для вывода

    file_shifr f;
    int option = -1;

    while (option != 0) {
        wcout << L"\nВыберите команду:\n 1. Зашифровать текст\n 2. Расшифровать текст\n 0. Выход" << endl;
        option = correctnumber(0, 2);

        switch (option) {
        case 1:
            Shifr(f, 1);  // Шифрование
            break;
        case 2:
            Shifr(f, 2);  // Дешифрование
            break;
        case 0:
            wcout << L"Выход из программы." << endl;
            return 0;
        default:
            wcout << L"Введите корректный номер (0-2)." << endl;
            break;
        }
    }

    return 0;
}
