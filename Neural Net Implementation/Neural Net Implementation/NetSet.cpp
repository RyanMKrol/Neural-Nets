//
//  NetSet.cpp
//  Neural Net Implementation
//
//  Created by Ryan Krol on 19/05/2017.
//  Copyright © 2017 Ryan Krol. All rights reserved.
//

#include "NetSet.hpp"

NetSet::NetSet(string dataLoc){
    
    Matrix blankMatrix;
    this->inputs = blankMatrix;
    this->outputs = new Matrix();
    this->classes = blankMatrix;
    this->bias = blankMatrix;
    this->count = 0;
    
}

NetSet::~NetSet(){
    free(this->outputs);
}

//Matrix inputs;
//Matrix outputs;
//Matrix classes;
//int count;
//Matrix bias;
