//
//  Linear_system.cpp
//  Solve_Gauss
//
//  Created by Максим Бачурин on 02.05.2018.
//  Copyright © 2018 Максим Бачурин. All rights reserved.
//

#include <cstdio>
#include <iostream>
#include <cmath>
#include <iomanip>
#include "Linear_system.h"

using namespace std;

const double EPS = 1e-9;

Linear_system:: Linear_system(int n) {
    coefficients.resize(n, vector<int>(n));
    right.resize(n);
    roots.resize(n);
    srand((int)time(NULL));
    for(int i = 0; i < n; i++) {
        roots[i] = rand()%5 + 1;
    }
    do {
        for(int i = 0; i < n; i++) {
            int sum = 0;
            for(int j = 0; j < n; j++) {
                coefficients[i][j] = rand()%10 + 1;
                sum += coefficients[i][j] * roots[j];
            }
            right[i] = sum;
        }
    }while(!solve(false));
}

void print_matrix(const vector<vector<double>> &vec,
                          const vector<double> &b) {
    cout << fixed << setprecision(3);
    int n = (int)vec.size();
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cout << vec[i][j] << '\t';
        }
        cout << b[i] << endl;
    }
    cout << endl;
}

bool Linear_system::solve(bool need_print) {
    int n = (int)coefficients.size();
    vector<vector<double>> coef(n, vector<double>(n));
    vector<double> b(n);
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            coef[i][j] = coefficients[i][j];
        }
        b[i] = right[i];
    }
    for(int i = 0; i < n; i++) {
        if(need_print) {
            cout << "Разделим " << i+1 << " строку на " <<
            coef[i][i] << endl;
        }
        double d = coef[i][i];
        if(abs(d) < EPS){
            return false;
        }
        for(int j = 0; j < n; j++) {
            coef[i][j] /= d;
        }
        b[i] /= d;
        if(need_print) {
            print_matrix(coef, b);
        }
        for(int j = 0; j < n; j++) {
            if(i == j)
                continue;
            if(need_print) {
                cout << "От " << j+1 << " отнимаем " << i+1
                << " строку, умноженную на " << coef[j][i] << endl;
            }
            double d = coef[j][i];
            for(int t = 0; t < n; t++) {
                coef[j][t] -= coef[i][t]*d;
            }
            b[j] -= b[i]*d;
        }
        if(need_print) {
            print_matrix(coef, b);
        }
    }
    if(need_print) {
        cout << "Ответ: \n";
        for(int i = 0; i < n; i++) {
            cout << "x" << i + 1 << " = " << b[i] << endl;
        }
        cout << endl;
    }
    return true;
}

void Linear_system::print(){
    cout << fixed << setprecision(3);
    int n = (int)coefficients.size();
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n - 1; j++) {
            if(coefficients[i][j] != 1)
                cout << coefficients[i][j];
            cout << "x" << j+1 << " + ";
        }
        if(coefficients[i][n-1] != 1)
            cout << coefficients[i][n-1];
        cout << "x" << n
        << " = " << right[i] << endl;
    }
    cout << endl;
}

bool Linear_system::check_answer(const vector<int> &ans) {
    return ans == roots;
}
