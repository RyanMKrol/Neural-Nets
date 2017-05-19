//
//  Network.cpp
//  Neural Net Implementation
//
//  Created by Ryan Krol on 18/05/2017.
//  Copyright © 2017 Ryan Krol. All rights reserved.
//

#include "Network.hpp"
#include <cmath>
#include <random>

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

//feed forward function
pair<Matrix,Matrix> Network::feedForward(Matrix inputs, Matrix weights, Matrix bias){
 
    Matrix net = weights.mult(inputs.horizontalMatrixConcat(bias));
    Matrix output = activation(net);
    
    return pair<Matrix,Matrix>(net, output);
}

//initialises a matrix of weights with a given width and height
Matrix Network::weightInit(double maxWeight, double width, double height){
    
    mt19937 rng;
    rng.seed(std::random_device()());
    uniform_int_distribution<std::mt19937::result_type> dist(-maxWeight, maxWeight);
    
    
    vector<vector<double>> arr(height,vector<double>(width));
    
    for(int i = 0; i < height; i++){
        for(int j = 0; j < width; j++){
            arr[i][j]  = dist(rng);
        }
    }
    return Matrix(arr);
}

//a lot of debugging will need to happen here
pair<double,double> Network::evaluate(Matrix inputs, Matrix weights, Matrix targetOutputs, Matrix targetClasses, Matrix bias){
    
    //[output net] = feedforward(inputs, weights, bias)
    Matrix outputs = (feedForward(inputs, weights, bias)).second;
    
    //error = sum_all_components((target_outputs – outputs)^2) / (sample_count * output_count)
    Matrix diffMatrix = targetOutputs.subtract(outputs);
    diffMatrix = diffMatrix.mult(diffMatrix);
    double errorSum = diffMatrix.getAbsoluteVal();
    //this could be wrong, test this later, it's different from the guide
    errorSum /= (2 * inputs.getUnderlying().size());
    
    //classes = classes_from_output_vectors(outputs)

    vector<vector<double>> outputsVector = outputs.getUnderlying();
    vector<double> classes(outputsVector.size());
    
    for(int i = 0; i < outputsVector.size(); i++){
        classes[i] = outputToClass(outputsVector[i]);
    }
    
    //c = sum_all_components(classes != target_classes)/sample_count
    vector<vector<double>> targetClassesVector = targetClasses.getUnderlying();
    double sumDiff = 0;
    
    for(int i = 0; i < classes.size(); i++){
        if(classes[i] != outputToClass(targetClassesVector[i]))
            sumDiff++;
    }
    
    sumDiff /= outputsVector.size();
    
    return pair<double,double>(errorSum, sumDiff);
}

//dummy backprop function
Matrix Network::backProp(Matrix inputs, Matrix weights, double learningRate, vector<double> bias){
    return weights;
}











