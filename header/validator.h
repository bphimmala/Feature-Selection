#ifndef VALIDATOR_H
#define VALIDATOR_H
#include <iostream>
#include <vector>
#include <string>
#include <cmath>
using namespace std;

double validator(vector<int>, vector<vector<double>> allInstances);
void normalize(vector<vector<double>> &allInstances);
double mean(vector<vector<double>> allInstances, int index);
double standardDeviation(vector<vector<double>> allInstances, int index, double mean);

#endif