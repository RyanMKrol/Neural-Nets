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

template <class T> class Matrix {
    
    vector<vector<T>> arr;
    
    public:
        void transpose();
        void add(Matrix<T>);
        void scalarMult(double);
        void mult(Matrix<T>);
        void hadamardMult(Matrix<T>);
        void kroneckerMult(Matrix<T>);
        void horizontalMatrixConcat();
};

#endif /* Matrix_hpp */
