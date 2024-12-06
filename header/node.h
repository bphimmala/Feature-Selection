#ifndef NODE_H
#define NODE_H
#include <cmath>
#include <vector>
#include <queue>
#include <string>
#include <iostream>
using namespace std;
#include "../header/validator.h"

class Node{
    private:
        double accuracy;    // basically h(n)
        int featureMax;
        int algorithm; // 0 = forward, 1 = backwards
        int newFeat;
        vector<int> currState;
        string dataset;
    public:
        Node(int algorithm, int featMax, string dataset);  // parent constructor
        Node(int newFeature, Node parent); // child constructor
        void updateState();
        bool isValid();
        bool isEmpty();
        bool operator<(const Node &) const; //overloading operators for prio queue
        bool operator>(const Node &) const;
        Node& operator=(const Node &);
        int getFeatureMax();
        double getAccuracy();
        void printState();
        int getAlgorithm();
};

#endif