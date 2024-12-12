#include "..\header\printMenu.h"

void printMenu() {
    int userFeatureChoice = 0;
    int userAlgorithmChoice = 0;
    int userDatasetChoice = 0;
    string dataset;
    int algorithm = 0;

    cout << "Welcome to ehix001-sphim001 Feature Selection Algorithm" << endl << endl;
    
    cout << "Type the number of the algorithm you want to run." << endl;
    cout << "1) Forward Selection" << endl;
    cout << "2) Backward Elimination" << endl << endl;

    cin >> userAlgorithmChoice;
    cout << endl;

    if (userAlgorithmChoice == 1) {
        algorithm = 0;
    }
    else if (userAlgorithmChoice == 2) {
        algorithm = 1;
    }
    
    cout << "Type the number of the dataset to use." << endl;
    cout << "1) Small Dataset" << endl;
    cout << "2) Large Dataset" << endl;
    cout << "3) Titanic Dataset" << endl;
    cin >> userDatasetChoice;
    cout << endl;

    if(userDatasetChoice == 1){
        dataset = "../include/small-test-dataset.txt";
    }
    else if(userDatasetChoice == 2){
        dataset = "../include/large-test-dataset.txt";
    }
    else if(userDatasetChoice == 3){
        dataset = "../include/titanic-dataset.txt";
    }
    else{
        cout << "Invalid Dataset Selected." << endl;
    }

    Node initialNode(algorithm, userFeatureChoice, dataset);
    Node solution = Search(initialNode);
    
    return;
}