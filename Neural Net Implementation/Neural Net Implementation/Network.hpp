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
#include "Matrix.hpp"

class Network{
    
    int numOutputClasses;
public:

    int outputToClass(vector<double>);
    vector<double> classToOutput(int);
    Network(int);
    
//    train
//    load data
//    feed-forward
//    evaluate network
//    backpropagation
//    output to class
//    class to output
//    activation
//    activation derivative
};

#endif /* Network_hpp */
