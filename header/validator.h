#ifndef VALIDATOR_H
#define VALIDATOR_H
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <cmath>
using namespace std;

double validator(vector<int>, string);
void normalize(vector<vector<double>> &allInstances);
double mean(vector<vector<double>> allInstances, int index);
double standardDeviation(vector<vector<double>> allInstances, int index, double mean);

#endif