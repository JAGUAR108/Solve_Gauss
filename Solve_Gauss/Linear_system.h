//
//  Linear_system.h
//  Solve_Gauss
//
//  Created by Максим Бачурин on 02.05.2018.
//  Copyright © 2018 Максим Бачурин. All rights reserved.
//

#ifndef Linear_system_h
#define Linear_system_h
#include <vector>
#include <ctime>
#include <cstdlib>

using namespace std;

class Linear_system {
    vector<vector<int>> coefficients;
    vector<int> right;
    vector<int> roots;
    
public:
    Linear_system(int n = 2);
    bool solve(bool need_print = true);
    void print();
    bool check_answer(const vector<int> &ans);
};

#endif /* Linear_system_h */
