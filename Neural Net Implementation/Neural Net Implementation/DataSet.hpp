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
    NetSet* getTrainingSet() const {return this->trainingSet;};
    NetSet* getValidationSet() const {return this->validationSet;};
    NetSet* getTestingSet() const {return this->testingSet;};
    ~DataSet();
    
};

#endif /* DataSet_hpp */
