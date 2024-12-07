#include "..\header\validator.h"
#include "..\header\readDataset.h"
#include <chrono>
using namespace std::chrono;

int main(){

    vector<int> featureSubset;

    cout << "Which Dataset?" << endl;
    cout << "1. Small" << endl;
    cout << "2. Large" << endl;

    int input;
    cin >> input;
    if(input == 1){
        featureSubset.push_back(3);
        featureSubset.push_back(5);
        featureSubset.push_back(7);
        cout << "Finding accuracy for feature subset {3, 5, 7}" << endl;
        auto start = high_resolution_clock::now();
        vector<vector<double>> allInstances = read("../include/small-test-dataset.txt");
        auto stop = high_resolution_clock::now();
        auto duration = duration_cast<milliseconds>(stop - start);
        cout << "Time taken to read in data: " << duration.count() << " ms.\n" << endl;

        start = high_resolution_clock::now();
        double acc = validator(featureSubset, allInstances);
        stop = high_resolution_clock::now();
        duration = duration_cast<milliseconds>(stop - start);
        cout << "Time taken to classify data: " << duration.count() << " ms.\n" << endl;

        cout << "accuracy: " << acc << "%" <<endl;
    }
    else if(input == 2){
        featureSubset.push_back(1);
        featureSubset.push_back(15);
        featureSubset.push_back(27);
        cout << "Finding accuracy for feature subset {1, 15, 27}" << endl;
        auto start = high_resolution_clock::now();
        vector<vector<double>> allInstances = read("../include/large-test-dataset.txt");
        auto stop = high_resolution_clock::now();
        auto duration = duration_cast<milliseconds>(stop - start);
        cout << "Time taken to read in data: " << duration.count() << " ms.\n" << endl;

        start = high_resolution_clock::now();
        double acc = validator(featureSubset, allInstances);
         stop = high_resolution_clock::now();
        duration = duration_cast<milliseconds>(stop - start);
        cout << "Time taken to classify data: " << duration.count() << " ms.\n" << endl;

        cout << "accuracy: " << acc << "%" << endl;
    }
    else{
        cout << "error opening dataset" << endl;
    }
    
    return 0;
}