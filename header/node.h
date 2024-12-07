#ifndef NODE_H
#define NODE_H
#include <cmath>
#include <vector>
#include "../header/validator.h"
#include "../header/readDataset.h"

class Node{
    private:
        double accuracy;    // basically h(n)
        int featureMax;
        int algorithm; // 0 = forward, 1 = backwards
        int newFeat;
        vector<int> currState;
        vector<vector<double>> dataset;
        string dataFile;
    public:
        Node(int algorithm, int featMax, string dataFile);  // parent constructor
        Node(int newFeature, Node parent); // child constructor
        void updateState();
        void printState();
        bool isValid();
        bool isEmpty();
        bool operator<(const Node &) const; //overloading operators for prio queue
        bool operator>(const Node &) const;
        Node& operator=(const Node &);
        int getFeatureMax();
        double getAccuracy();
        int getAlgorithm();
};

#endif