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
};

#endif /* NetSet_hpp */
