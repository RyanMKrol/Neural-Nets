//
//  Network.cpp
//  Neural Net Implementation
//
//  Created by Ryan Krol on 18/05/2017.
//  Copyright © 2017 Ryan Krol. All rights reserved.
//

#include "Network.hpp"

//assumes the matrix has 1 row
int Network::outputToClass(Matrix result){
    
    vector<vector<double>> arr = result.getUnderlying();
    
    for(int i = 0; i < arr[0].size(); i++){
        if(arr[0][i] != 0)
            return i + 1;
    }
    
    return 0;
    
}
