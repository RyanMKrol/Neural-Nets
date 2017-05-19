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
#include "Network.hpp"

using namespace std;

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    
    vector<vector<double>> one = {{1,2},{3,4}};
    vector<vector<double>> two = {{0,5},{6,7}};
    vector<vector<double>> three = {{1,0,0,0}};
    
    Matrix*one_m = new Matrix(one);
    Matrix*two_m = new Matrix(two);
    Matrix*three_m = new Matrix(three);
    
    Matrix other = one_m->kroneckerMult(*two_m);
    cout << netThing.outputToClass(*three_m) << endl;

    
    
    return 0;
}
