#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>

using namespace std;

int main(){
    string filename = "small-test-dataset.txt";
    ifstream inputFile(filename);
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

    for(int i = 0; i < allInstances.size(); i++){
        cout << "instance " << i << ": " << endl;
        for(int j = 0; j < allInstances.at(i).size(); j++){
        cout << allInstances.at(i).at(j) << " ";
        }
        cout << endl;
    }
    return 0;
}
