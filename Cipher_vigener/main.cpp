#include <iostream>
#include <string>
#include <fstream>
#include <Windows.h>
#include <locale>
#include <cwctype>

using namespace std;

// ��������� ��� �������� �������� ������ � �����
struct file_shifr {
    wstring inputfile, outputfile;
    wstring key;
};

// �������� ������������ ����� �����
template <typename T>
T correctnumber(T min, T max) {
    T x;
    while (((wcin >> x).fail()) || (wcin.peek() != L'\n') || (x < min) || (x > max)) {
        wcout << L"������! ������� ���������� �����: >= " << min << L" � <= " << max << endl;
        wcin.clear();
        wcin.ignore(INT_MAX, L'\n');
    }
    return x;
}

wchar_t VigenereShift(wchar_t ch, wchar_t key, bool encrypt = true) {
    bool isRussianUpper = (ch >= L'�' && ch <= L'�');
    bool isRussianLower = (ch >= L'�' && ch <= L'�');
    bool isEnglishUpper = (ch >= L'A' && ch <= L'Z');
    bool isEnglishLower = (ch >= L'a' && ch <= L'z');

    int alphabetSize = 0;
    int chCode = 0;
    int keyCode = 0;
    int offset = 0;
    int newCode = 0;

    if (isRussianUpper || isRussianLower) {
        alphabetSize = 32;
        chCode = isRussianUpper ? ch - L'�' : ch - L'�';
        keyCode = (key >= L'�' && key <= L'�') ? key - L'�' : key - L'�';
        offset = encrypt ? keyCode : -keyCode;
        newCode = (chCode + offset + alphabetSize) % alphabetSize;
        if (newCode < 0) {
            newCode += alphabetSize;
        }
        return isRussianUpper ? (newCode + L'�') : (newCode + L'�');
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
        return ch;  // ���� ������ �� ����������� ���������, ���������� ��� ��� ���������
    }
}


// ������� ���������� � ������������
void Shifr(file_shifr& f, int x) {
    wchar_t symbol;
    int i = 0;

    wcout << L"\n������� �������� ����� ��� ����� (��� .txt): " << endl;
    wcin >> f.inputfile;
    wcout << L"������� �������� ����� ��� ������ (��� .txt): " << endl;
    wcin >> f.outputfile;
    wcout << L"������� ���� ��� �����������: " << endl;
    wcin >> f.key;

    wifstream in(f.inputfile + L".txt");  // �������� �������� �����
    wofstream out(f.outputfile + L".txt");  // �������� ��������� �����

    locale loc("ru_RU.UTF-8");
    in.imbue(loc);
    out.imbue(loc);

    if (!in.is_open() || !out.is_open()) {
        wcout << L"\n������ �������� �����!" << endl;
        return;
    }

    // �������������� ����� � ������ ������� ��� ��������� ����������
    for (wchar_t& c : f.key) {
        c = towlower(c);
    }

    // ������� ����������/������������
    while (in.get(symbol)) {
        wchar_t k = f.key[i % f.key.size()];  // ������ ����� �� ������ ����� �����
        symbol = VigenereShift(symbol, k, (x == 1));  // true ��� ����������, false ��� ������������
        i++;

        out.put(symbol);  // ������ � �������� ����
    }

    wcout << (x == 1 ? L"\n����� ����������" : L"\n����� �����������") << endl;

    in.close();
    out.close();
}

int main() {
    setlocale(LC_ALL, "ru_RU.UTF-8");
    SetConsoleCP(65001);  // UTF-8 ��������� ��� �����
    SetConsoleOutputCP(65001);  // UTF-8 ��������� ��� ������

    file_shifr f;
    int option = -1;

    while (option != 0) {
        wcout << L"\n�������� �������:\n 1. ����������� �����\n 2. ������������ �����\n 0. �����" << endl;
        option = correctnumber(0, 2);

        switch (option) {
        case 1:
            Shifr(f, 1);  // ����������
            break;
        case 2:
            Shifr(f, 2);  // ������������
            break;
        case 0:
            wcout << L"����� �� ���������." << endl;
            return 0;
        default:
            wcout << L"������� ���������� ����� (0-2)." << endl;
            break;
        }
    }

    return 0;
}
