#ifndef NODE_H
#define NODE_H
#include <cmath>
#include <vector>
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
        Node(int, int);  // parent constructor
        Node(int, Node); // child constructor
        void updateState();
        double FSevaluationFunction(vector<int>);
        double BEevaluationFunction(vector<int>);
        bool isValid();
        bool operator<(const Node &) const; //overloading operators for prio queue
        bool operator>(const Node &) const;
        int getFeatureMax();
        double getAccuracy();
        int getAlgorithm();
};

#endif