#ifndef VALIDATOR_H
#define VALIDATOR_H
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
using namespace std;

double validator(vector<int>, string);
double mean(vector<vector<double>> allInstances, int index);
void normalize(vector<vector<double>> &allInstances);

#endif