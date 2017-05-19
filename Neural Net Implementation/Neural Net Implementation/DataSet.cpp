//
//  DataSet.cpp
//  Neural Net Implementation
//
//  Created by Ryan Krol on 19/05/2017.
//  Copyright © 2017 Ryan Krol. All rights reserved.
//

#include "DataSet.hpp"

DataSet::DataSet(string trainingLoc, string validationLoc, string testingLoc){
    
    trainingSet = new NetSet(trainingLoc);
    validationSet = new NetSet(validationLoc);
    testingSet = new NetSet(testingLoc);
}

DataSet::~DataSet(){
    free(this->trainingSet);
    free(this->validationSet);
    free(this->testingSet);
}
