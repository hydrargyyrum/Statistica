#pragma once
#include <iostream>
#include <vector>
#include <cmath> 
#include <cstdlib>
#include "statisticalCharacteristics.h"

double f(vector<double> data1, vector<double> data2) {
	return disp(data1, mean(data1)) / disp(data2, mean(data2));
}
