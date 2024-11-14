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

}