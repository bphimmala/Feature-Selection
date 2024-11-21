#include "..\header\Search.h"

Node Search(Node parent) {
    priority_queue<Node> frontier;
    frontier.push(parent);

    while (!frontier.empty()) {
        Node temp = frontier.top();
        frontier.pop();
        expand(temp, frontier);
        Node newTop = frontier.top();
        if (newTop.getAccuracy() < temp.getAccuracy()) {
            return temp;
        }
    }
    
    return parent; //INVALID -- should not reach
}

void expand(Node parentToExpand, priority_queue<Node> &frontier) {
    for(int i = 0; i < parentToExpand.getFeatureMax(); i++){
        Node temp(i, parentToExpand);
        if(temp.isValid()){
            temp.updateState();
            frontier.push(temp);
        }
    }
}