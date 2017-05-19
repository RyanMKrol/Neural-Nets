//
//  Network.hpp
//  Neural Net Implementation
//
//  Created by Ryan Krol on 18/05/2017.
//  Copyright © 2017 Ryan Krol. All rights reserved.
//

#ifndef Network_hpp
#define Network_hpp

#include <stdio.h>
#include <string>
#include "Matrix.hpp"
#include "DataSet.hpp"

class Network{
    
    int numOutputClasses;
    DataSet *data;
    
public:

    int outputToClass(vector<double>);
    vector<double> classToOutput(int);
    Matrix activation(Matrix);
    Matrix activationDerivative(Matrix);
    Matrix weightInit(double,double,double);
    pair<Matrix,Matrix> feedForward(Matrix,Matrix, Matrix);
    Matrix backProp(Matrix,Matrix,double,vector<double>);
    pair<double,double> evaluate(Matrix,Matrix, Matrix,Matrix,Matrix);
    Network(int, string, string, string);
    
    ~Network();
};

#endif /* Network_hpp */


//    train
//    load data
//    feed-forward
//    evaluate network
//    backpropagation
//    output to class
//    class to output
//    activation
//    activation derivative
