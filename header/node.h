#ifndef NODE_H
#define NODE_H
#include <cmath>
#include <vector>
#include <queue>
#include <iostream>
using namespace std;

class Node{
    private:
        double accuracy;    // basically h(n)
        int featureMax;
        int algorithm; // 0 = forward, 1 = backwards
        int newFeat;
        vector<int> currState;
    public:
        Node(int algorithm, int featMax);  // parent constructor
        Node(int newFeature, Node parent); // child constructor
        void updateState();
        double FSevaluationFunction(vector<int>);
        double BEevaluationFunction(vector<int>);
        bool isValid();
        bool operator<(const Node &) const; //overloading operators for prio queue
        bool operator>(const Node &) const;
        Node& operator=(const Node &);
        int getFeatureMax();
        double getAccuracy();
        void printState();
        // int getAlgorithm();
};

#endif