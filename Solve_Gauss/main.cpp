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
                cout << "Это правильный ответ! Идём дальше!" << endl;
                break;
            }
            else {
                system.solve();
            }
        }
    }
    cout << "Поздравляем! Вы прошли практический курс обучения!\n";
}

int main() {
    learning();
    return 0;
}

