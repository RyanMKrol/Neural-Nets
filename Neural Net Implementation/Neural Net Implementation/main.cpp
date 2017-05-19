//
//  main.cpp
//  Neural Net Implementation
//
//  Created by Ryan Krol on 18/05/2017.
//  Copyright © 2017 Ryan Krol. All rights reserved.
//

#include <iostream>
#include <vector>
#include "Matrix.hpp"

using namespace std;

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    
    vector<vector<double>> one = {{1},{1},{1}};
    vector<vector<double>> two = {{2,3,4}};
    
    Matrix*one_m = new Matrix(one);
    Matrix*two_m = new Matrix(two);
    
    Matrix other = one_m->mult(*two_m);

    return 0;
}
