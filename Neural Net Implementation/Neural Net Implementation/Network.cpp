//
//  Network.cpp
//  Neural Net Implementation
//
//  Created by Ryan Krol on 18/05/2017.
//  Copyright © 2017 Ryan Krol. All rights reserved.
//

#include "Network.hpp"
#include <cmath>

Network::Network(int numClasses, string trainingLoc, string validationLoc, string testingLoc){
    this->numOutputClasses = numClasses;
    this->data = new DataSet(trainingLoc, validationLoc, testingLoc);
}

Network::~Network(){
    free(this->data);
}

//assumes the matrix has 1 row
int Network::outputToClass(vector<double> result){
    
    for(int i = 0; i < result.size(); i++){
        if(result[i] != 0)
            return i + 1;
    }
    
    return 0;
    
}

//turn a class number into an output vector
vector<double> Network::classToOutput(int classNum) {
    
    vector<double> result(this->numOutputClasses,0);
    result[classNum-1] = 1;
    
    
    return result;
}

//applies the activation function to a matrix, component-wise
Matrix Network::activation(Matrix a) {
    
    vector<vector<double>> arr = a.getUnderlying();
    
    for(int i = 0; i < arr.size(); i++){
        for(int j = 0; j < arr[0].size(); j++){
            
            double val = arr[i][j];
            val = tanh(val);
            val++;
            val /= 2;
            arr[i][j] = val;
        }
    }
    
    return Matrix(arr);
}

//applies derivative of the activation function to a matrix, component-wise
Matrix Network::activationDerivative(Matrix a){
    
    vector<vector<double>> arr = a.getUnderlying();
    
    for(int i = 0; i < arr.size(); i++){
        for(int j = 0; j < arr[0].size(); j++){
            
            double val = arr[i][j];
            val = tanh(val);
            val = pow(val,2);
            val = 1 - val;
            val /= 2;
            arr[i][j] = val;
        }
    }
    
    return Matrix(arr);
}


pair<Matrix,Matrix> Network::feedForward(Matrix inputs, Matrix weights, Matrix bias){
 
    Matrix net = weights.mult(inputs.horizontalMatrixConcat(bias));
    Matrix output = activation(net);
    
    return pair<Matrix,Matrix>(net, output);
    
}
















