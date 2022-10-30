#pragma once
#include <iostream>
#include <vector>
#include <cmath> 
#include "statisticalCharacteristics.h"
using namespace std;

double t(vector <double> data1, vector <double> data2) {
	double tmp = 0;
	tmp = (mean(data1) - mean(data2)) /
		S(disp(data1, mean(data1)), disp(data2, mean(data2)), data1.size(), data2.size()) /
		sqrt(1.0 / (double)data1.size() + 1.0 / (double)data2.size());
	return tmp;
}