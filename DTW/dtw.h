#ifndef _DTW_H_
#define _DTW_H_

#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>

using namespace std;

double dtw(vector<vector<double>>& inputAduio, vector<vector<double>>& temAduio);
vector<double> dtwSynchronous(vector<vector<double>>& inputAduio, vector<vector<vector<double>>>& temsAudio);

#endif