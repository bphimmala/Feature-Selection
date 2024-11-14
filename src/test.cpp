#include "../header/node.h"

int main() {
    srand(time(NULL));

    Node parent(0, 4); //forward node with featmax 4
    Node parent2(1, 5); //backward node with featmax 5

    cout << "Print state for forward node (empty)" << endl;
    parent.printState();

    cout << "Print state for backward node (full)" << endl;
    parent2.printState();

    cout << "Random accuracy for parent one: " << parent.getAccuracy();
    cout << endl;
    cout << "Random accuracy for parent two: " << parent2.getAccuracy();
    cout << endl;
    
    // cout << "here";
    Node child(4, parent); //mod 4, forward search (add 4 to empty)
    if (child.isValid()) {
        // cout << "Correct";
        child.updateState();
    }
    Node child2(4, parent2); //mod 4, backward search (remove 4 from full)
    if (child2.isValid()) {
        child2.updateState();
    }

    cout << "Print state for child node (Valid, updated)" << endl;
    child.printState();

    cout << "Print state for child node 2 (Valid, updated)" << endl;
    child2.printState();

    Node child3(6, child2); //mod 4, backward search (remove 4 from full)
    if (child3.isValid()) {
        cout << "BAD" << endl;
        child3.updateState();
    }
    cout << "Print state for child node 3 (Same)" << endl;
    child3.printState();

    cout << "Random accuracy for child one: " << child.getAccuracy();
    cout << endl;
    cout << "Random accuracy for child two: " << child2.getAccuracy();
    cout << endl;

    cout << "FORWARD SEARCH TEST" << endl;
    Node childNew1(2, child); //mod 4, forward search (add 4 to empty)
    if (childNew1.isValid()) {
        // cout << "Correct";
        childNew1.updateState();
    }
    childNew1.printState();

    Node childNew2(1, childNew1);
    if (childNew2.isValid()) {
        // cout << "Correct";
        childNew2.updateState();
    }
    childNew2.printState();

    Node childNew3(3, childNew2);
    if (childNew3.isValid()) {
        // cout << "Correct";
        childNew3.updateState();
    }
    childNew3.printState();

    Node childNewINVALID(5, childNew3); // this one should NOT print, featMax has been reached
    if (childNewINVALID.isValid()) {
        cout << "INVALID" << endl;
        childNewINVALID.updateState();
    }
    childNewINVALID.printState();

    cout << "BACKWARD SEARCH TEST" << endl;
    parent2.printState();
    Node childB2(4, parent2); //mod 4, backward search (remove 4 from full)
    if (childB2.isValid()) {
        childB2.updateState();
    }
    childB2.printState();
    Node childB3(3, childB2); //mod 3, backward search (remove 3 from full)
    if (childB3.isValid()) {
        childB3.updateState();
    }
    childB3.printState();
    Node childB4(1, childB3); //mod 1, backward search (remove 1 from full)
    if (childB4.isValid()) {
        childB4.updateState();
    }
    childB4.printState();
    Node childB5(2, childB4); //mod 2, backward search (remove 2 from full)
    if (childB5.isValid()) {
        childB5.updateState();
    }
    childB5.printState();
    Node childB6(5, childB5); //mod 5, backward search (remove 3 from full)
    if (childB6.isValid()) {
        cout << "VALID" << endl;
        childB6.updateState();
    }
    childB6.printState();
    cout << "empty";
    Node childB7(3, childB6); //mod 3, backward search SHOULD NOT PRINT
    if (childB7.isValid()) {
        cout << "INVALID" << endl;
        childB7.updateState();
    }
    childB7.printState();
    cout << "empty";
    return 0;
}