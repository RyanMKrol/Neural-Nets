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

//Matrix transpose();
//Matrix add(Matrix);
//Matrix scalarMult(double);
//Matrix mult(Matrix);
//Matrix hadamardMult(Matrix);
//Matrix kroneckerMult(Matrix);
//Matrix horizontalMatrixConcat();
//Matrix(vector<vector>);
