#include "../header/node.h"

Node::Node(int algo, int featMax) {
    // parent constructor
    accuracy = evaluationFunction();
    featureMax = featMax;
    algorithm = algo;
    newFeat = 0;

    if (algorithm) {
        for (int i = 0; i < featureMax; ++i) {
            currState.push_back(i+1);
        }
    }
}

Node::Node(int newFeature, Node parent) {
    // child constructor
    accuracy = evaluationFunction();

    featureMax = parent.getFeatureMax();
    algorithm = parent.getAlgorithm();
    newFeat = newFeature;
    for (int i = 0; i < parent.currState.size()-1; ++i) {
        currState.push_back(parent.currState.at(i));
    }
}

void Node::updateState(){
    // add the New Feature to the array
    currState.push_back(newFeat);
}

double Node::evaluationFunction(){
    const long max_rand = 1000000L;
    double lowerBound = 0;
    double upperBound = 10;
    double randNum = lowerBound + (upperBound - lowerBound) * (rand() % max_rand) / max_rand;
    
    return randNum;
}