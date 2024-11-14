#include "../header/node.h"

Node::Node(int algo, int featMax) {
    // parent constructor
    featureMax = featMax;
    algorithm = algo;
    newFeat = 0;

    if (algorithm) {
        for (int i = 0; i < featureMax; ++i) {
            currState.push_back(i+1);
        }
    }
    
    if(algo == 0){
        accuracy = FSevaluationFunction(currState);
    }
    else if(algo == 1){
        accuracy == BEevaluationFunction(currState);
    }
}

Node::Node(int newFeature, Node parent) {
    // child constructor

    featureMax = parent.getFeatureMax();
    algorithm = parent.getAlgorithm();
    newFeat = newFeature;

    for (int i = 0; i < parent.currState.size()-1; ++i) {
        currState.push_back(parent.currState.at(i));
    }

    if (algorithm) {
        for (int i = 0; i < featureMax; ++i) {
            currState.push_back(i+1);
        }
    }
    
    if(algorithm == 0){
        accuracy = FSevaluationFunction(currState);
    }
    else if(algorithm == 1){
        accuracy == BEevaluationFunction(currState);
    }
}

void Node::updateState(){
    // add the New Feature to the array
    currState.push_back(newFeat);
}

double Node::FSevaluationFunction(vector<int>){
    const long max_rand = 1000000L;
    double lowerBound = 0;
    double upperBound = 10;
    double randNum = lowerBound + (upperBound - lowerBound) * (rand() % max_rand) / max_rand;
    
    return randNum;
}

double Node::BEevaluationFunction(vector<int>){
    const long max_rand = 1000000L;
    double lowerBound = 0;
    double upperBound = 10;
    double randNum = lowerBound + (upperBound - lowerBound) * (rand() % max_rand) / max_rand;
    
    return randNum;
}


bool Node::isValid(){
    for (int i = 0; i < featureMax; i++){
        if(i == newFeat){
            return false;
        }
    }

    return true;
}

bool Node::operator<(const Node & N) const{
    return ((accuracy > N.accuracy));
}

bool Node::operator>(const Node & N) const{
    return ((accuracy < N.accuracy));
}