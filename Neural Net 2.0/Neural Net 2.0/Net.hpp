//
//  Net.hpp
//  Neural Net 2.0
//
//  Created by Ryan Krol on 19/05/2017.
//  Copyright © 2017 Ryan Krol. All rights reserved.
//

#ifndef Net_hpp
#define Net_hpp

#include <stdio.h>
#include <vector>
#include <iostream>
#include "Neuron.hpp"

using namespace std;

class Net
{
public:
    Net(const vector<unsigned> &topology);
    void feedForward(const vector<double> &inputVals);
    void backProp(const vector<double> &targetVals);
    void getResults(vector<double> &resultVals) const;
    double getRecentAverageError(void) const { return m_recentAverageError; }
    
private:
    vector<Layer> m_layers; // m_layers[layerNum][neuronNum]
    double m_error;
    double m_recentAverageError;
    static double m_recentAverageSmoothingFactor;
};

#endif /* Net_hpp */
