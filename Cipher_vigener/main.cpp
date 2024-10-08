#include <iostream>
#include <string>
#include <fstream>
#include <Windows.h>

using namespace std;

struct file_shifr
{
    string inputfile, outputfile;
    string key;
};

// �������� �� ��������� ������
template <typename T>
T correctnumber(T min, T max) {
    T x;
    while (((cin >> x).fail()) || (cin.peek() != '\n') || (x < min) || (x > max)) {
        cout << "������! ������� ���������� �����: >= " << min << " � <= " << max << endl;
        cin.clear();
        cin.ignore(INT_MAX, '\n');
    }
    return x;
}

void Shifr(int x)
{
    file_shifr f;

    cout << "������� �������� ����� ��� �����: ";
    cin >> f.inputfile;
    f.inputfile += ".txt"; 

    cout << "������� �������� ����� ��� ������: ";
    cin >> f.outputfile;
    f.outputfile += ".txt";  

    cout << "������� ���� ��� �����������: ";
    cin >> f.key;

    unsigned char symbol;
    int i = 0;
    unsigned char n;
    unsigned char k;
    const int ASCII_SIZE = 256;  

    ifstream in(f.inputfile, ios::binary);
    ofstream out(f.outputfile, ios::binary);

    if (!in.is_open()) {
        cout << "\n������ �������� �������� �����!" << endl;
        return;
    }
    if (!out.is_open()) {
        cout << "\n������ �������� ��������� �����!" << endl;
        return;
    }

    cout << "����������/������������:\n";
    while (in.get((char&)symbol)) {
        k = static_cast<unsigned char>(f.key[i % f.key.size()]);

        if (x == 1)  // �����������
            n = (symbol + k) % ASCII_SIZE;  
        else         // �����������
            n = (symbol - k + ASCII_SIZE) % ASCII_SIZE;  

        
        i += 1;
        out.put(n);
    }

    cout << "\n����� ��������� (����������/�����������)." << endl;
    in.close();
    out.close();
}

int main()
{
    setlocale(LC_ALL, "Russian");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    int option = -1;
    while (option != 0)
    {
        cout << "\n�������� �������:\n 1. ����������� �����\n 2. ������������ �����\n 0. �����" << endl;
        option = correctnumber(0, 2);

        switch (option)
        {
        case 1:
            Shifr(1);  // �����������
            break;
        case 2:
            Shifr(2);  // �����������
            break;
        case 0:
            return 0;
        default:
            cout << "������� ���������� ����� (0-2)" << endl;
            break;
        }
    }

    return 0;
}
