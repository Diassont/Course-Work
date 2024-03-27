#include <iostream>
#include <Windows.h>
#include <vector>

using namespace std;

//Функція для виведення меню гри
void menu() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    cout << " |-----------------------|\n";
    cout << " |- Гра Хрестики-нулики -|\n";
    cout << " |-----------------------|\n"; cout << endl;
    cout << " 1. Мета та правила гри\n";
    cout << " 2. Розпочати гру\n";
    cout << " 3. Закінчити гру\n";
}

//Функція для виведення дошки на екран
void board_out(const vector<vector<char>>& board) {
    for (int i = 0; i < 3; ++i) {
        for (int t = 0; t < 3; ++t) {
            if (t != 0) {
                cout << "|";
            }
            if (board[i][t] == ' ') {
                cout << "   ";
            }
            else {
                cout << " " << board[i][t] << " ";
            }
        }
        cout << endl;
        if (i != 2) {
            cout << "---|---|---\n";
        }
    }
}

int main() {
    bool game = true;
    while (game) {
        cout << endl; menu();
        int letter;
        cout << " Введіть номер пункту меню: ";
        cin >> letter;
        switch (letter) {

        case 1: {
            cout << endl;
            cout << " *** Мета: ***" << endl;
            cout << " Скласти виграшну комбінацію з трьох своїх символів (хрестиків або нуликів) по горизонталі, вертикалі або діагоналі." << endl << endl;
            cout << " *** Правила гри: ***" << endl;
            cout << " 1. Гравці обирають, хто буде грати хрестиками, а хто нуликами." << endl;
            cout << " 2. Гравцi по черзі роблять хід, вводячи номер комірки (від 1 до 9), куди хочуть поставити свій символ." << endl;
            cout << " 3. Програма перевіряє, чи вільна комірка, чи не вийшов гравець за межі поля, чи не використовується вже цей символ." << endl;
            cout << " 4. Перемагає той, хто першим складе виграшну комбінацію." << endl;
            break;
        }

        case 2: {
            vector<vector<char>> board(3, vector<char>(3));
            for (int i = 0; i < 3; ++i) {
                for (int t = 0; t < 3; ++t) {
                    board[i][t] = ' ';
                }
            }
            board_out(board);
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