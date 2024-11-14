#include "../header/node.h"

int main() {
    Node parent(0, 4); //forward node with featmax 4
    Node parent2(1, 5); //backward node with featmax 5

    cout << "Print state for forward node (empty)" << endl;
    parent.printState();

    cout << "Print state for backward node (full)" << endl;
    parent2.printState();

    cout << "Random accuracy for parent one: " << parent.getAccuracy();
    cout << endl;
    cout << "Random accuracy for parent one: " << parent.getAccuracy();
    cout << endl;
    
    return 0;
}