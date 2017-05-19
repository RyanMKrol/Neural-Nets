//
//  Network.cpp
//  Neural Net Implementation
//
//  Created by Ryan Krol on 18/05/2017.
//  Copyright © 2017 Ryan Krol. All rights reserved.
//

#include "Network.hpp"


Network::Network(int numClasses){
    this->numOutputClasses = numClasses;
}

//assumes the matrix has 1 row
int Network::outputToClass(vector<double> result){
    
    for(int i = 0; i < result.size(); i++){
        if(result[i] != 0)
            return i + 1;
    }
    
    return 0;
    
}

vector<double> Network::classToOutput(int classNum) {
    
    vector<double> result(this->numOutputClasses,0);
    result[classNum-1] = 1;
    
    
    return result;
}
