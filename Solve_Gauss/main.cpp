//
//  main.cpp
//  Solve_Gauss
//
//  Created by Максим Бачурин on 02.05.2018.
//  Copyright © 2018 Максим Бачурин. All rights reserved.
//

#include <iostream>
#include "Linear_system.h"

void learning() {
    cout << "Начнём с системы размера 2х2: \n";
    for(int i = 2; i <= 6; i++) {
        while(true) {
            Linear_system system(i);
            cout << "Решите систему: \n";
            system.print();
            cout << "Какой у Вас получился ответ? Введите " << i <<
            " корня через пробел: \n";
            vector<int> ans(i);
            for(int j = 0; j < i; j++) {
                cin >> ans[j];
            }
            if(system.check_answer(ans)) {
                cout << "Это правильный ответ! Идём дальше!\n" << endl;
                break;
            }
            else {
                system.solve();
            }
        }
    }
    cout << "Поздравляем! Вы прошли практический курс обучения!\n\n\n";
}

void solver() {
    cout << "Введите размерность матрицы: \n";
    int n = 0;
    do {
        string s;
        getline(cin, s);
        if(s.size() > 1) {
            continue;
        }
        n = s[0] - '0';
    }while(!(n >= 1 && n <= 9));
    cout << "Введите целые коэффициенты СЛАУ вместе с правой частью:\n";
    vector<vector<int>> coefficients(n, vector<int>(n));
    vector<int> right(n);
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> coefficients[i][j];
        }
        cin >> right[i];
    }
    Linear_system input_system;
    if(input_system.set_coefficients(coefficients, right)) {
        input_system.solve();
    }
    else {
        cout << "Данная матрица не удовлетворяет условию метода.\n\n";
    }
}

void menu() {
    while(true) {
        cout << "Выберите режим:\n1 Решатель СЛАУ\n2 Практическое обучение\n3 Выход\n";
        char c;
        do {
            cin >> c;
        }while(!(c >= '1' && c <= '3'));
        if(c == '3') {
            break;
        }
        if(c == '1') {
            solver();
        }
        if(c == '2') {
            learning();
        }
    }
}

int main() {
    menu();
    return 0;
}
