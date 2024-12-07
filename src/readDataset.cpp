#include "../header/readDataset.h"

vector<vector<double>> read(string dataFile){
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

    return allInstances;
}