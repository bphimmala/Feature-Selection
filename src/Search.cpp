#include "..\header\Search.h"

Node Search(Node parent) {
    priority_queue<Node> frontier;
    Node emptyNode(1, 0);
    frontier.push(parent);
    
    if (parent.getAlgorithm() == 0) {
        cout << "Using no features and \"random\" evaluation, I get an accuracy of " << parent.getAccuracy() << "%" << endl << endl;
    }
    if (parent.getAlgorithm() == 1) {
        cout << "Using all features and \"random\" evaluation, I get an accuracy of " << parent.getAccuracy() << "%" << endl << endl;
    }

    cout << "Beginning search." << endl << endl;
    
    while (!frontier.empty()) {
        Node temp = frontier.top();
        frontier.pop();
        expand(temp, frontier);
        Node newTop = frontier.top();
        if (newTop.getAccuracy() <= temp.getAccuracy()) {
            cout << "Warning! Accuracy decreased!" << endl;
            cout << "Search has finished." << endl;
            cout << "The best feature set is ";
            temp.printState();
            cout << ", which has an accuracy of " << temp.getAccuracy() << "%!" << endl;
            return temp;
        }
        cout << "Feature set ";
        newTop.printState();
        cout << " was best, accuracy is " << newTop.getAccuracy() << "%" << endl << endl;
    }
    
    return parent; //INVALID -- should not reach
}

void expand(Node parentToExpand, priority_queue<Node> &frontier) {
    Node emptyNode(1, 0);

    for(int i = 1; i <= parentToExpand.getFeatureMax(); i++){
        Node temp(i, parentToExpand);
        if(temp.isValid()){
            temp.updateState();
            cout << "Using feature(s) ";
            temp.printState();
            cout << " has an accuracy of " << temp.getAccuracy() << "%" << endl;
            if (temp.getAccuracy() == 0) {
                cout << endl;
                return;
            }
            frontier.push(temp);
        }
    }
    cout << endl;
}