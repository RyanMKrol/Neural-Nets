//
//  Matrix.hpp
//  Neural Net Implementation
//
//  Created by Ryan Krol on 18/05/2017.
//  Copyright © 2017 Ryan Krol. All rights reserved.
//

#ifndef Matrix_hpp
#define Matrix_hpp

#include <stdio.h>
#include <vector>

using namespace std;

class Matrix {
    
    vector<vector<double>> arr;
    
    public:
    vector<vector<double>> getUnderlying();
    Matrix transpose();
    Matrix add(Matrix);
    Matrix scalarMult(double);
    Matrix mult(Matrix);
    Matrix hadamardMult(Matrix);
    Matrix kroneckerMult(Matrix);
    Matrix horizontalMatrixConcat();
    Matrix(vector<vector<double>>);
};

#endif /* Matrix_hpp */
