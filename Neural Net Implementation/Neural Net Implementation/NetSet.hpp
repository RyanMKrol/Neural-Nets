//
//  NetSet.hpp
//  Neural Net Implementation
//
//  Created by Ryan Krol on 19/05/2017.
//  Copyright © 2017 Ryan Krol. All rights reserved.
//

#ifndef NetSet_hpp
#define NetSet_hpp

#include <stdio.h>
#include "Matrix.hpp"

class NetSet{
    Matrix inputs;
    Matrix outputs;
    Matrix classes;
    int count;
    Matrix bias;
    
public:
    NetSet(string);
    
    Matrix getInputs()const {return this->inputs;};
    Matrix getOutputs()const {return this->outputs;};
    Matrix getClasses()const {return this->classes;};
    Matrix getBias()const {return this->bias;};
    int getCount()const {return this->count;};
};

#endif /* NetSet_hpp */
