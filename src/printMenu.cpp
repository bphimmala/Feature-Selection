#include "..\header\printMenu.h"

void printMenu() {
    srand(time(0));

    int userFeatureChoice = 0;
    int userAlgorithmChoice = 0;
    int algorithm = 0;

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

    cout << "Beginning search." << endl << endl;

    if (userAlgorithmChoice == 1) {
        algorithm = 0;
    }
    else if (userAlgorithmChoice == 2) {
        algorithm = 1;
    }
    
    Node initialNode(algorithm, userFeatureChoice);
    cout << "(Warning, Accuracy has decreased!)" << endl;
    cout << "Finished search!! The best feature subset is ";
    Node solution = Search(initialNode);
    solution.printState();
    cout << ", which has an accuracy of " << solution.getAccuracy() << "%";
    
    return;
}