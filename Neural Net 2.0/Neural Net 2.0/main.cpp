//
//  main.cpp
//  Neural Net 2.0
//
//  Created by Ryan Krol on 19/05/2017.
//  Copyright © 2017 Ryan Krol. All rights reserved.
//

#include <iostream>
#include <vector>
#include "Net.hpp"

#include <sstream>
#include <string>
#include <fstream>


using namespace std;

vector<unsigned> topology = {2,2,1};

int main(int argc, const char * argv[]) {
    
    
    std::ifstream infile("trainingData.txt");
    std::string line;
    
    vector<vector<double>>inputs;
    vector<vector<double>>outputs;
    
    //reads in the file and creates the matrices
    while (std::getline(infile, line)) {
        std::istringstream iss(line);
        double a, b, c;
        if (iss >> a >> b >> c) {
            inputs.push_back({a,b});
            outputs.push_back({c});
        } else {
            break;
        }
    }
    
    Net myNet("netWeights.txt");
//    Net myNet(topology);
    
    vector<vector<double>>resultVals;
    vector<double>result;
    
    for(int i = 0; i < inputs.size(); i++){
        myNet.feedForward(inputs[i]);
        myNet.backProp(outputs[i]);
        myNet.getResults(result);
        resultVals.push_back(result);
    
//        cout << inputs[i][0] << " " << inputs[i][1] << endl;
        cout << "expected output: " << outputs[i][0] << endl << "returned result: " << result[0] << endl << endl;
        
//        cout << "Net recent average error: " << myNet.getRecentAverageError() << endl;
    }
    
//    myNet.outputLayers("netWeights.txt");
    
//    for(int i = 0; i < resultVals.size();i++){
//        cout << resultVals[i][0] << " " << outputs[i][0] << endl;
//    }
    
    return 0;
}
