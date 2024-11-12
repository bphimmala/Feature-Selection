#include "../header/node.h"

Node::Node(int algorithm){
    accuracy = 0;

    if (algorithm == 1){ // forward selection

    }
    if (algorithm == 2){ // backward elimination

    }
}

Node::Node(int algorithm, Operations inputOp, Node parent){
    
    operation = inputOp;

    if (algorithm == 1){ // forward selection
    
    }
    if(algorithm == 2){ // backward elimination

    }
}

void Node::updateState(int algorithm){

}

double Node::evaluationFunction(){
    const long max_rand = 1000000L;
    double lowerBound = 0;
    double upperBound = 10;
    double randNum = lowerBound + (upperBound - lowerBound) * (rand() % max_rand) / max_rand;
    
    return randNum;
}