#include "..\header\printMenu.h"

void printMenu() {
    int userFeatureChoice = 0;
    int userAlgorithmChoice = 0;

    cout << "Welcome to ehix001-sphim001 Feature Selection Algorithm" << endl << endl;
    
    cout << "Please enter the total number of features: ";
    cin >> userFeatureChoice;
    cout << endl;

    cout << "Type the number of the algorithm you want to run." << endl;
    cout << "1) Forward Selection" << endl;
    cout << "2) Backward Elimination" << endl;
    cout << "3) Special Algorithm" << endl << endl;
    cin >> userAlgorithmChoice;
    cout << endl;

    cout << "Using no features and \"random\" evaluation, I get an accuracy of ";
    // evaluation ?
    cout << "%" << endl << endl;

    cout << "Beginning search.";

    Node initialNode(userAlgorithmChoice, userFeatureChoice);
    // call search function

    return;
}