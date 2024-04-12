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

//Функція для виведення гральної дошки
void board_out(const vector<vector<char>>& board, bool show_numbers) {
    for (int i = 0; i < 3; ++i) {
        for (int t = 0; t < 3; ++t) {
            if (t != 0) {
                cout << "|";
            }
            if (board[i][t] == ' ') {
                if (show_numbers) {
                    cout << " " << (i * 3 + t + 1) << " ";
                }
                else {
                    cout << "   ";
                }
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
            // Створення гральної дошки
            vector<vector<char>> board(3, vector<char>(3));
            for (int i = 0; i < 3; ++i) {
                for (int t = 0; t < 3; ++t) {
                    board[i][t] = ' ';
                }
            }

            // Обирання символів гравцями
            char player1, player2, currentPlayer;
            cout << "Гравець 1, оберіть свій символ (X або O): ";
            cin >> player1;

            // Перевірка на коректність вибору символу гравця 1
            while (player1 != 'X' && player1 != 'O') {
                cout << "Неправильний символ! Оберіть X або O: ";
                cin >> player1;
            }

            // Визначення символу для гравця 2
            player2 = (player1 == 'X') ? 'O' : 'X';
            currentPlayer = player1;

            // Вивід дошки з номерами клітин перед початком гри
            cout << endl << "Гральна дошка:\n";
            board_out(board, true);
            cout << endl;

            while (true) {
                int number;
                cout << "Гравець " << currentPlayer << ", введіть свій хід (1-9): ";
                cin >> number;
                if (number < 1 || number > 9 || board[(number - 1) / 3][(number - 1) % 3] != ' ') {
                    cout << "Неправильний хід, спробуйте ще раз." << endl;
                    continue;
                }

                // Вивід дошки після кожного ходу
                board[(number - 1) / 3][(number - 1) % 3] = currentPlayer;
                board_out(board, false);

                bool win = false;

                // Перевірка рядків
                for (int i = 0; i < 3; ++i) {
                    if (board[i][0] == currentPlayer && board[i][1] == currentPlayer && board[i][2] == currentPlayer) {
                        win = true;
                        break;
                    }
                }

                // Перевірка стовпців
                for (int i = 0; i < 3; ++i) {
                    if (board[0][i] == currentPlayer && board[1][i] == currentPlayer && board[2][i] == currentPlayer) {
                        win = true;
                        break;
                    }
                }

                // Перевірка діагоналей
                if (board[0][0] == currentPlayer && board[1][1] == currentPlayer && board[2][2] == currentPlayer) {
                    win = true;
                }
                if (board[0][2] == currentPlayer && board[1][1] == currentPlayer && board[2][0] == currentPlayer) {
                    win = true;
                }

                // Якщо є переможець
                if (win) {
                    cout << "Гравець " << currentPlayer << " переміг!" << endl;
                    cout << "Грати ще раз? (Так/Ні): ";
                    string answer;
                    cin >> answer;
                    if (answer != "Так") {
                        game = false;
                        break;
                    }

                    // Очищення дошки
                    for (int i = 0; i < 3; ++i) {
                        for (int t = 0; t < 3; ++t) {
                            board[i][t] = ' ';
                        }
                    }

                    // Зміна гравця
                    currentPlayer = (currentPlayer == player1) ? player2 : player1;
                    continue;
                }

                // Перевірка на нічию
                bool draw = true;
                for (int i = 0; i < 3; ++i) {
                    for (int t = 0; t < 3; ++t) {
                        if (board[i][t] == ' ') {
                            draw = false;
                            break;
                        }
                    }
                }

                // Якщо нічия
                if (draw) {
                    cout << "Нічия!" << endl;
                    cout << "Грати ще раз? (Так/Ні): ";
                    string answer;
                    cin >> answer;
                    if (answer != "Так") {
                        game = false;
                        break;
                    }

                    // Очищення дошки
                    for (int i = 0; i < 3; ++i) {
                        for (int t = 0; t < 3; ++t) {
                            board[i][t] = ' ';
                        }
                    }

                    // Зміна гравця
                    currentPlayer = (currentPlayer == player1) ? player2 : player1;
                    continue;
                }

                // Зміна ходу наступного гравця
                currentPlayer = (currentPlayer == player1) ? player2 : player1;
            }
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
}