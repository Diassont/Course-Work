#include <iostream>
#include <locale.h>

using namespace std;

//������� ��� ��������� ���� ���
void menu() {
    setlocale(LC_ALL, "Rus");

    cout << " |-----------------------|\n";
    cout << " |- ��� ��������-������ -|\n";
    cout << " |-----------------------|\n"; cout << endl;
    cout << " 1. ���� �� ������� ���\n";
    cout << " 2. ��������� ���\n";
    cout << " 3. ���i����� ���\n";
}

int main() {
    bool game = true;
    while (game) {
        cout << endl; menu();
        int letter;
        cout << " ����i�� ����� ������ ����: ";
        cin >> letter;
        switch (letter) {

        case 1: {
            cout << endl;
            cout << " *** ����: ***" << endl;
            cout << " ������� �������� ����i���i� � ����� ���� ������i� (�������i� ��� �����i�) �� ����������i, ��������i ��� �i������i." << endl << endl;
            cout << " *** ������� ���: ***" << endl;
            cout << " 1. �����i ��������, ��� ���� ����� ����������, � ��� ��������." << endl;
            cout << " 2. �����i �� ����i ������� �i�, ������� ����� ���i��� (�i� 1 �� 9), ���� ������ ��������� ��i� ������." << endl;
            cout << " 3. �������� �����i���, �� �i���� ���i���, �� �� ������ ������� �� ���i ����, �� �� ��������������� ��� ��� ������." << endl;
            cout << " 4. �������� ���, ��� ������ ������ �������� ����i���i�." << endl;
            break;
        }

        case 2: {
            // ��� ��� ���
            break;
        }

        case 3: {
            game = false;
            break;
        }

        default: {
            cout << "����������� ����! ��������� �� ���.\n";
            break;
        }
        }
    }
    return 0;
}