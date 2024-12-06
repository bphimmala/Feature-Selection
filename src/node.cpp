#include "../header/node.h"

Node::Node(int algo, int featMax, string userDataset) {
    // parent constructor
    featureMax = featMax;
    algorithm = algo;
    newFeat = 0;
    dataset = userDataset;

    if (algorithm) { // backwards elimination
        for (int i = 0; i < featureMax; ++i) {
            currState.push_back(i+1);
        }
    }
    else{
        currState.push_back(0);
    }
    
    if (!algorithm) {
        //forward, thus empty
        accuracy = 0;
    }
    else {
        accuracy = validator(currState, dataset);
    }
}

Node::Node(int newFeature, Node parent) {
    // child constructor

    featureMax = parent.featureMax;
    algorithm = parent.algorithm;
    dataset = parent.dataset;
    newFeat = newFeature;

    for (int i = 0; i < parent.currState.size(); ++i) {
        currState.push_back(parent.currState.at(i));
    }
    
    accuracy = validator(this->currState, this->dataset);
}

void Node::updateState(){
    
    if (!algorithm) {
    // add the New Feature to the array
        if ((currState.size() == 1) && (currState.at(0) == 0)) {
            //erase if the parent 0 is there
            currState.erase(currState.begin());
        }
        currState.push_back(newFeat);
    }
    else {
    // remove the feature from the array
        for (int i = 0; i < currState.size(); i++) {
            if (currState.at(i) == newFeat) {
                currState.erase(currState.begin()+i);
            }
        }
    }
    accuracy = validator(this->currState, this->dataset);
    if (isEmpty()) {
        accuracy = 0;
    }
}

bool Node::isValid(){
    bool found = false;
    
    for (int i = 0; i < currState.size(); i++){
        if(currState.at(i) == newFeat){
            found = true;
        }
    }
    if (!algorithm && (found || (currState.size() == featureMax))) {
        // forward case
        return false;
    }
    if (algorithm && (!found || (currState.size() == 0))) {
        // backward case
        return false;
    }
    if (newFeat > featureMax) {
        return false;
    }
    return true;
}

bool Node::isEmpty() {
    return (currState.empty());
}

bool Node::operator<(const Node & N) const{
    return ((accuracy < N.accuracy));
}

bool Node::operator>(const Node & N) const{
    return ((accuracy > N.accuracy));
}

Node& Node::operator=(const Node & N) {
    for (int i = 0; i < N.currState.size()-1; ++i) {
        currState.push_back(N.currState.at(i));
    }
    accuracy = N.accuracy;
    featureMax = N.featureMax;
    algorithm = N.algorithm;
    newFeat = N.newFeat;
    if (this != &N) {            
        currState = move(N.currState);
    }
    return *this;
}

int Node::getFeatureMax() {
    return featureMax;
}

double Node::getAccuracy() {
    return accuracy;
}

void Node::printState() {
    cout << "{";
    if (currState.size() > 1) {
        for (int i = 0; i < currState.size()-1; ++i) {
            cout << currState.at(i) << ", ";
        }
        cout << currState.at(currState.size()-1);
    }
    else if (currState.size() == 1) {
        if (currState.at(0) != 0) {
            cout << currState.at(0);
        }
    }
    cout << "}";
    return;
}

int Node::getAlgorithm() {
    return algorithm;
}