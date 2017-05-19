//
//  NetSet.cpp
//  Neural Net Implementation
//
//  Created by Ryan Krol on 19/05/2017.
//  Copyright © 2017 Ryan Krol. All rights reserved.
//

#include "NetSet.hpp"
#include <sstream>
#include <string>
#include <fstream>

NetSet::NetSet(string dataLoc){
    
    std::ifstream infile("iris_test.dat");
    std::string line;
    
    vector<vector<double>>inputs;
    vector<vector<double>>outputs;
    
    //reads in the file and creates the matrices
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
    
    Matrix blankMatrix;
    this->inputs = Matrix(inputs);
    this->outputs = Matrix(outputs);
    
    this->classes = blankMatrix;
    this->bias = blankMatrix;
    this->count = (int)inputs.size();

}
