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
        int algorithm;
        int newFeat;
        vector<int> currState;
        vector<int> initialArray;
    public:
        Node(int, int);  // child constructor
        Node(int, Node); // parent constructor
        void updateState();
        double evaluationFunction();
        bool isValid();
        bool operator<(const Node &) const; //overloading operators for prio queue
        bool operator>(const Node &) const;
        int getFeatureMax();
};

#endif