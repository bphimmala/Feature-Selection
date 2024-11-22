#include "..\header\Search.h"

Node Search(Node parent) {
    priority_queue<Node> frontier;
    frontier.push(parent);
    
    cout << "Using no features and \"random\" evaluation, I get an accuracy of " << parent.getAccuracy() << "%" << endl << endl;

    cout << "Beginning search." << endl << endl;
    
    while (!frontier.empty()) {
        Node temp = frontier.top();
        frontier.pop();
        expand(temp, frontier);
        Node newTop = frontier.top();
        if (newTop.getAccuracy() < temp.getAccuracy()) {
            return temp;
        }
        cout << "Feature set ";
        newTop.printState();
        cout << " was best, accuracy is " << newTop.getAccuracy() << "%" << endl << endl;
    }
    
    return parent; //INVALID -- should not reach
}

void expand(Node parentToExpand, priority_queue<Node> &frontier) {
    for(int i = 1; i <= parentToExpand.getFeatureMax(); i++){
        Node temp(i, parentToExpand);
        if(temp.isValid()){
            temp.updateState();
            cout << "Using feature(s) ";
            temp.printState();
            cout << " accuracy is " << temp.getAccuracy() << "%" << endl;
            Node newNode = temp;
            frontier.push(newNode);
        }
    }
    cout << endl;
}