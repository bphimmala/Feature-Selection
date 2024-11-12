#ifndef NODE_H
#define NODE_H
#include <cmath>
#include <iostream>
using namespace std;

enum Operations {MODIFY1, MODIFY2, MODIFY3, MODIFY4};

class Node{
    private:
        double accuracy;    // basically h(n)
        int initialArray[4];
        Operations operation;
    public:
        Node(int);
        Node(int, Operations, Node);
        double evaluationFunction();
};

#endif