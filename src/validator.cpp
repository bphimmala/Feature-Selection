#include "../header/validator.h"

double validator(vector<int> featureSubset, vector<vector<double>> allInstances){
    int nearestNeighbor;
    double correct = 0;
        
    for(int i = 0; i < allInstances.size(); i++){ // iterate through all instances and pick instance i to use as test
        vector<double> testingInstance = allInstances.at(i);
        double distance = INFINITY;

        for(int j = 0; j < allInstances.size(); j++){ // iterate through all other instances to test i against
            if(j != i){
                vector<double> comparingInstance = allInstances.at(j);
                double sumSq = 0;

                for(int k = 0; k < featureSubset.size(); k++){ // begins Euclidean distance for feature subset
                    sumSq = sumSq + pow((testingInstance.at(featureSubset.at(k)) - comparingInstance.at(featureSubset.at(k))), 2);
                }

                double euclideanDist = sqrt(sumSq);
                if(euclideanDist < distance){
                    distance = euclideanDist;
                    nearestNeighbor = j;
                }
            }
        }

        if (allInstances.at(nearestNeighbor).at(0) == testingInstance.at(0)) { // count how many correct classifications
            ++correct;
        }
    }
    return (correct / allInstances.size());
}

void normalize(vector<vector<double>> &allInstances) {

    for (int i = 1; i <= allInstances.at(0).size()-1; ++i) {              // for every feature
        double featureMean = mean(allInstances, i);                       // get the mean of that feature
        double stdDev = standardDeviation(allInstances, i, featureMean);  // get the std dev of that feature
        for (int j = 0; j < allInstances.size(); ++j) {                   // for every instance
            double x = allInstances.at(j).at(i);                          // get the value for that feature of that instance
            allInstances.at(j).at(i) = (x - featureMean)/stdDev;          // replace it
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