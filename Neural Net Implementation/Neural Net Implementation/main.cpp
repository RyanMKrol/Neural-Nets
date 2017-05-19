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
#include <sstream>
#include <string>
#include <fstream>

using namespace std;

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    
    std::ifstream infile("iris_test.dat");
    std::string line;
    
    vector<vector<double>>inputs;
    vector<vector<double>>outputs;
    
    while (std::getline(infile, line)) {
        
        cout << line << endl;
        std::istringstream iss(line);
        double a, b, c, d, e, f, g;
        if (iss >> a >> b >> c >> d >> e >> f >> g) {
            inputs.push_back({a,b,c,d});
            outputs.push_back({e,f,g});
        } else {
            break;
        }
    }
    
    Matrix thing = Matrix(inputs);
    
    Network thingNet = Network(3,"iris_test.dat", "iris_validation.dat", "iris_training.dat");
    Matrix other = thingNet.activation(thing);
    other = thingNet.activationDerivative(thing);
    return 0;
}
