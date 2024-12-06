#include "../header/validator.h"

double validator(vector<int> featureSubset, string dataFile){
    ifstream inputFile(dataFile);
    vector<vector<double>> allInstances;

    char delimiter = ' ';

    if(inputFile.is_open()){
        string line;
        double i = 0;
        while(getline(inputFile, line, '\n')){
            vector<double> tempVector;
            istringstream s(line);
            while(s >> i || !s.eof()){
                if(s.fail()){
                    s.clear();
                    string temp;
                    s >> temp;
                    continue;
                }
                else{
                    tempVector.push_back(i);
                }
            }
            allInstances.push_back(tempVector);
        }
    }
    
    //////////////////////////////
    // prints out all instances //
    //////////////////////////////

    // for(int i = 0; i < allInstances.size(); i++){
    //     cout << "instance " << i << ": " << endl;
    //     for(int j = 0; j < allInstances.at(i).size(); j++){
    //     cout << allInstances.at(i).at(j) << " ";
    //     }
    //     cout << endl;
    // }

    //////////////////////////////
    // ROUGH CODE FOR CLASSIFER //
    //////////////////////////////

    // vector<vector<double>> allInstances;
    // vector<int> featureSubset;

    // int nearestNeighbor;
    // int correct;

    // for(int i = 0; i < allInstances.size(); i++){ // THIS ONE IS THE ONE WE ARE TESTING
    //     vector<double> testingInstance = allInstances.at(i);
    //     double distance = max();
    //     for(int j = 0; i < allInstances.size(); j++){ // THIS IS WHAT WE'RE TESTING AGAINST
    //         if(j != i){
    //             vector<double> comparingInstance = allInstances.at(j);
    //             double sumSq = 0;
    //             for(int k = 0; k < featureSubset.size(); k++){ // FINDS THE FEATURES
    //                 sumSq = sumSq + (testingInstance.at(featureSubset.at(k)) - comparingInstance.at(featureSubset.at(k)))^2;
    //             }
    //             double euclideanDist = sqrt(sumSq);
    //             if(euclideanDist < distance){
    //                 distance = euclideanDist;
    //                 nearestNeighbor = j;
    //             }
    //         }
    //     }
    //     if (allInstances.at(j).at(0) == testingInstance.at(0)) {
    //         ++correct;
    //     }
    // }

    // return correct / allInstances.size();
    return 0.0;
}