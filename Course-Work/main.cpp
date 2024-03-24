#include <iostream>
#include <locale.h>

using namespace std;

//Функція для виведення меню гри
void menu() {
    setlocale(LC_ALL, "Rus");

    cout << " |-----------------------|\n";
    cout << " |- Гра Хрестики-нулики -|\n";
    cout << " |-----------------------|\n"; cout << endl;
    cout << " 1. Мета та правила гри\n";
    cout << " 2. Розпочати гру\n";
    cout << " 3. Закiнчити гру\n";
}

int main() {
    bool game = true;
    while (game) {
        cout << endl; menu();
        int letter;
        cout << " Введiть номер пункту меню: ";
        cin >> letter;
        switch (letter) {

        case 1: {
            cout << endl;
            cout << " *** Мета: ***" << endl;
            cout << " Скласти виграшну комбiнацiю з трьох своїх символiв (хрестикiв або нуликiв) по горизонталi, вертикалi або дiагоналi." << endl << endl;
            cout << " *** Правила гри: ***" << endl;
            cout << " 1. Гравцi обирають, хто буде грати хрестиками, а хто нуликами." << endl;
            cout << " 2. Гравцi по черзi роблять хiд, вводячи номер комiрки (вiд 1 до 9), куди хочуть поставити свiй символ." << endl;
            cout << " 3. Програма перевiряє, чи вiльна комiрка, чи не вийшов гравець за межi поля, чи не використовується вже цей символ." << endl;
            cout << " 4. Перемагає той, хто першим складе виграшну комбiнацiю." << endl;
            break;
        }

        case 2: {
            // Код для гри
            break;
        }

        case 3: {
            game = false;
            break;
        }

        default: {
            cout << "Некоректний вибір! Спробуйте ще раз.\n";
            break;
        }
        }
    }
    return 0;
}