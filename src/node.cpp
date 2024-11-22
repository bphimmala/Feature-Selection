#include "../header/node.h"

Node::Node(int algo, int featMax) {
    // parent constructor
    featureMax = featMax;
    algorithm = algo;
    newFeat = 0;

    if (algorithm) { // backwards elimination
        for (int i = 0; i < featureMax; ++i) {
            currState.push_back(i+1);
        }
    }
    else{
        currState.push_back(0);
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

    featureMax = parent.featureMax;
    algorithm = parent.algorithm;
    newFeat = newFeature;

    for (int i = 0; i < parent.currState.size(); ++i) {
        currState.push_back(parent.currState.at(i));
    }
    
    if(algorithm == 0){
        accuracy = FSevaluationFunction(currState);
    }
    else if(algorithm == 1){
        accuracy == BEevaluationFunction(currState);
    }
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
}

double Node::FSevaluationFunction(vector<int> curr){
    float randNum = ((float)rand() /(float)RAND_MAX) * 100.0f;
    // cout << " FS acc: " << randNum << endl;
    return randNum;
}

double Node::BEevaluationFunction(vector<int> curr){
    float randNum = ((float)rand() /(float)RAND_MAX) * 100.0f;
    // cout << " BE acc: " << randNum << endl;
    return randNum;
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
        currState = std::move(N.currState);
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