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
    
    normalize(allInstances);
    
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

    int nearestNeighbor;
    double correct = 0;

    for(int i = 0; i < allInstances.size(); i++){ // THIS ONE IS THE ONE WE ARE TESTING
        vector<double> testingInstance = allInstances.at(i);
        double distance = INFINITY;

        for(int j = 0; j < allInstances.size(); j++){ // THIS IS WHAT WE'RE TESTING AGAINST
            if(j != i){
                vector<double> comparingInstance = allInstances.at(j);
                double sumSq = 0;

                for(int k = 0; k < featureSubset.size(); k++){ // FINDS THE FEATURES
                    sumSq = sumSq + pow((testingInstance.at(featureSubset.at(k)) - comparingInstance.at(featureSubset.at(k))), 2);
                }

                double euclideanDist = sqrt(sumSq);
                if(euclideanDist < distance){
                    distance = euclideanDist;
                    nearestNeighbor = j;
                }
            }
        }

        if (allInstances.at(nearestNeighbor).at(0) == testingInstance.at(0)) {
            ++correct;
        }
    }

    return (correct / allInstances.size());
}

void normalize(vector<vector<double>> &allInstances) {

    for (int i = 1; i <= allInstances.at(0).size()-1; ++i) {     // for every feature
        double featureMean = mean(allInstances, i);              // get the mean of that feature
        double stdDev = standardDeviation(allInstances, i, featureMean);                                      // change based on function like above, get the std dev of that feature
        for (int j = 0; j < allInstances.size(); ++j) {          // for every instance
            double x = allInstances.at(j).at(i);                 // get the value for that feature of that instance
            allInstances.at(j).at(i) = (x - featureMean)/stdDev; // replace it
        }
    }
}

double mean(vector<vector<double>> allInstances, int index) {
    double sum = 0;

    for (int i = 0; i < allInstances.size(); ++i) {
        sum = sum + allInstances.at(i).at(index);
    }

    return (sum / allInstances.size());
}

double standardDeviation(vector<vector<double>> allInstances, int index, double mean){
    double sum = 0;

    for(int i = 0; i < allInstances.size(); i++){
        sum = sum + pow((allInstances.at(i).at(index) - mean), 2);
    }
    
    return sqrt(sum / (allInstances.size()));
}