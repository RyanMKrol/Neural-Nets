//
//  Matrix.cpp
//  Neural Net Implementation
//
//  Created by Ryan Krol on 18/05/2017.
//  Copyright © 2017 Ryan Krol. All rights reserved.
//

#include "Matrix.hpp"

//constructor
Matrix::Matrix(vector<vector<double>> newArr){
    this->arr = newArr;
}

//get the underlying vector
vector<vector<double>> Matrix::getUnderlying(){
    return this->arr;
}

//returns the transposed matrix
Matrix Matrix::transpose(){
    
    int rows = (int)this->arr.size();
    int cols = (int)this->arr[0].size();
    
    vector<vector<double>> newArr(cols,vector<double>(rows));
    
    for(int i = 0; i < cols; i++){
        for(int j = 0; j< rows; j++){
            newArr[i][j] = this->arr[j][i];
        }
    }
    
    return Matrix(newArr);
}

//adds this matrix to another
Matrix Matrix::add(Matrix b){
    
    vector<vector<double>> otherUnderlying = b.getUnderlying();
    vector<vector<double>> result (otherUnderlying.size(), vector<double>(otherUnderlying[0].size()));
    
    for(int i = 0; i < otherUnderlying.size(); i++){
        for(int j = 0; j < otherUnderlying[0].size(); j++){
            result[i][j] = this->arr[i][j] + otherUnderlying[i][j];
        }
    }
    
    return Matrix(result);
}

//multiplies matrix by a scalar value
Matrix Matrix::scalarMult(double val){
    
    vector<vector<double>> result (this->arr.size(), vector<double>(this->arr[0].size()));
    
    for(int i = 0; i < this->arr.size(); i++){
        for(int j = 0; j < this->arr[0].size(); j++){
            result[i][j] = this->arr[i][j] * val;
        }
    }
    
    return Matrix(result);
}

//result of multiplying this matrix by another. this assumes that the matrices are compatible
Matrix Matrix::mult(Matrix b){
    
    vector<vector<double>> other = b.getUnderlying();
    
    int newRows = (int)this->arr.size();
    int newCols = (int)other[0].size();
    
    vector<vector<double>> result (newRows, vector<double>(newCols));
    
    
    double val;
    for(int i = 0; i < newRows; i++){
        for(int j = 0; j < newCols; j++){
            val = 0;
            for(int k = 0; k < this->arr[0].size();k++){
                val += this->arr[i][k] * other[k][j];
            }
            result[i][j] = val;
        }
    }
    
    return Matrix(result);
}

//result of doing a hadamard multiply on this and another matrix
Matrix Matrix::hadamardMult(Matrix b){
    
    vector<vector<double>> other = b.getUnderlying();
    vector<vector<double>> result (this->arr.size(), vector<double>(this->arr[0].size()));
    
    for(int i = 0; i < this->arr.size(); i++){
        for(int j = 0; j < this->arr[0].size(); j++){
            result[i][j] = this->arr[i][j] * other[i][j];
        }
    }
    
    return Matrix(result);
}

// this could be a bit trickier, i'll try it tomorrow
//Matrix Matrix::kroneckerMult(Matrix b){
//    
//    vector<vector<double>> other = b.getUnderlying();
//    vector<vector<double>> result (this->arr.size(), vector<double>(this->arr[0].size()));
//    
//    for(int i = 0; i < this->arr.size(); i++){
//        for(int j = 0; j < this->arr[0].size(); j++){
//            result[i][j] = this->arr[i][j] * other[i][j];
//        }
//    }
//    
//    return Matrix(result);
//}

//result of doing a hadamard multiply on this and another matrix

//concatenates the rows of two matrices
Matrix Matrix::horizontalMatrixConcat(Matrix b){
    
    vector<vector<double>> other = b.getUnderlying();
    vector<vector<double>> result (this->arr.size(), vector<double>(this->arr[0].size() + other[0].size()));
    
    for(int i = 0; i < this->arr.size();i++){
        for(int j = 0; j < this->arr[0].size(); j++){
            result[i][j] = this->arr[i][j];
        }
    }
    
    for(int i = 0; i < other.size();i++){
        for(int j = (int)this->arr[0].size(); j < this->arr[0].size() + other[0].size(); j++){
            result[i][j] = other[i][j - this->arr[0].size()];
        }
    }
    
    return Matrix(result);
}

//Matrix kroneckerMult(Matrix);
