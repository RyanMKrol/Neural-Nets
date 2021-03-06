//
//  Net.cpp
//  Neural Net 2.0
//
//  Created by Ryan Krol on 19/05/2017.
//  Copyright © 2017 Ryan Krol. All rights reserved.
//

#include "Net.hpp"
#include <cassert>
#include <fstream>

double Net::m_recentAverageSmoothingFactor = 100.0; // Number of training samples to average over


void Net::getResults(vector<double> &resultVals) const
{
    resultVals.clear();
    
    for (unsigned n = 0; n < m_layers.back().size() - 1; ++n) {
        resultVals.push_back(m_layers.back()[n].getOutputVal());
    }
}

void Net::backProp(const vector<double> &targetVals)
{
    // Calculate overall net error (RMS of output neuron errors)
    
    Layer &outputLayer = m_layers.back();
    m_error = 0.0;
    
    for (unsigned n = 0; n < outputLayer.size() - 1; ++n) {
        double delta = targetVals[n] - outputLayer[n].getOutputVal();
        m_error += delta * delta;
    }
    m_error /= outputLayer.size() - 1; // get average error squared
    m_error = sqrt(m_error); // RMS
    
    // Implement a recent average measurement
    
    m_recentAverageError =
    (m_recentAverageError * m_recentAverageSmoothingFactor + m_error)
    / (m_recentAverageSmoothingFactor + 1.0);
    
    // Calculate output layer gradients
    
    for (unsigned n = 0; n < outputLayer.size() - 1; ++n) {
        outputLayer[n].calcOutputGradients(targetVals[n]);
    }
    
    // Calculate hidden layer gradients
    
    for (unsigned layerNum = (unsigned)m_layers.size() - 2; layerNum > 0; --layerNum) {
        Layer &hiddenLayer = m_layers[layerNum];
        Layer &nextLayer = m_layers[layerNum + 1];
        
        for (unsigned n = 0; n < hiddenLayer.size(); ++n) {
            hiddenLayer[n].calcHiddenGradients(nextLayer);
        }
    }
    
    // For all layers from outputs to first hidden layer,
    // update connection weights
    
    for (unsigned layerNum = (unsigned)m_layers.size() - 1; layerNum > 0; --layerNum) {
        Layer &layer = m_layers[layerNum];
        Layer &prevLayer = m_layers[layerNum - 1];
        
        for (unsigned n = 0; n < layer.size() - 1; ++n) {
            layer[n].updateInputWeights(prevLayer);
        }
    }
}

void Net::feedForward(const vector<double> &inputVals)
{
    assert(inputVals.size() == m_layers[0].size() - 1);
    
    // Assign (latch) the input values into the input neurons
    for (unsigned i = 0; i < inputVals.size(); ++i) {
        m_layers[0][i].setOutputVal(inputVals[i]);
    }
    
    // forward propagate
    for (unsigned layerNum = 1; layerNum < m_layers.size(); ++layerNum) {
        Layer &prevLayer = m_layers[layerNum - 1];
        for (unsigned n = 0; n < m_layers[layerNum].size() - 1; ++n) {
            m_layers[layerNum][n].feedForward(prevLayer);
        }
    }
}

//creates a new blank network
Net::Net(const vector<unsigned> &topology) {
    unsigned numLayers = (unsigned)topology.size();
    for (unsigned layerNum = 0; layerNum < numLayers; ++layerNum) {
        m_layers.push_back(Layer());
        unsigned numOutputs = layerNum == topology.size() - 1 ? 0 : topology[layerNum + 1];
        
        // We have a new layer, now fill it with neurons, and
        // add a bias neuron in each layer.
        for (unsigned neuronNum = 0; neuronNum <= topology[layerNum]; ++neuronNum) {
            m_layers.back().push_back(Neuron(numOutputs, neuronNum));
            cout << "Made a Neuron!" << endl;
        }
        
        // Force the bias node's output to 1.0 (it was the last neuron pushed in this layer):
        m_layers.back().back().setOutputVal(1.0);
    }
}

//creates a new net using previously trained weights
Net::Net(const string fileLoc) {
    
    ifstream infile(fileLoc);
    vector<unsigned> topology;
    
    double a;
    double b;
    
    infile >> a;
    
    for(int i = 0; i < a; i++){
        infile >> b;
        topology.push_back(b);
    }
    
    unsigned numLayers = (unsigned)topology.size();
    for (unsigned layerNum = 0; layerNum < numLayers; ++layerNum) {
        m_layers.push_back(Layer());
        unsigned numOutputs = layerNum == topology.size() - 1 ? 0 : topology[layerNum + 1];
        
        // We have a new layer, now fill it with neurons, and
        // add a bias neuron in each layer.
        for (unsigned neuronNum = 0; neuronNum <= topology[layerNum]; ++neuronNum) {
            
            vector<double> neuronWeights;
            
            for(int i = 0; i < numOutputs; i++){
                infile >> b;
                neuronWeights.push_back(b);
            }
            
            m_layers.back().push_back(Neuron(numOutputs, neuronNum, neuronWeights));
            
            cout << "Made a Neuron!" << endl;
        }
        cout << endl;
    }
    
}

//outputs the networks weights to a file
void Net::outputLayers(const string fileLoc) const {
    
    ofstream file;
    file.open (fileLoc, ios::out | ios::trunc);
    
    file << m_layers.size() << "\n";
    
    for(int i = 0; i < m_layers.size(); i++){
        file << m_layers[i].size() - 1 << " ";
    }
    
    file << "\n";
    
    if (file.is_open()) {
        for(int i = 0; i < m_layers.size() - 1; i++){
            for(int n = 0; n < m_layers[i].size(); n++){
                for(int w = 0; w < m_layers[i][n].getOutputWeights().size(); w++){
                    cout << m_layers[i][n].getOutputWeights()[w].weight << " " << endl;
                    file << m_layers[i][n].getOutputWeights()[w].weight << " ";
                }
                file << "\n";
            }
        }
        
        file.close();
    }
}
