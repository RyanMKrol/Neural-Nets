//
//  DataSet.hpp
//  Neural Net Implementation
//
//  Created by Ryan Krol on 19/05/2017.
//  Copyright © 2017 Ryan Krol. All rights reserved.
//

#ifndef DataSet_hpp
#define DataSet_hpp

#include <stdio.h>
#include <string>
#include "NetSet.hpp"

class DataSet {
    
    int inputCount;
    int outputCount;
    NetSet *trainingSet;
    NetSet *validationSet;
    NetSet *testingSet;
    
public:
    DataSet(string,string,string);
    ~DataSet();
    
};

#endif /* DataSet_hpp */


//data_set
//input_count
//output_count
//training_set
//inputs
//outputs
//classes
//count
//bias
//validation_set
//inputs
//outputs
//classes
//count
//bias
//test_set
//inputs
//outputs
//classes
//count
//bias
