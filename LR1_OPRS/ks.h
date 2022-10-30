#pragma once
#include <iostream>
#include <vector>
#include <cmath> 
#include <cstdlib>
#include "statisticalCharacteristics.h"
using namespace std;

double KS(vector<double> F, vector<double> F0) { // Вычисление значения статистики Колмогорова-Смирнова
	double difference = 0;
	double maxDif = -1;
	int n = F.size();
	for (int i = 0; i < n; i++)
	{
		difference = abs(F[i] - F0[i]);
		if (difference >= maxDif) maxDif = difference;
	}
	return maxDif;
}

vector <double> F0(vector<double> data) { // Вычисление функции F0
	int n = data.size();
	vector <double> tmp(n);
	for (int i = 0; i < n; i++)
		tmp[i] = (double)(i + 1) / n;
	return tmp;
}

vector <double> F(vector<double> data) { // Вычисление функции F
	int n = data.size();
	vector <double> tmp(n);
	for (int i = 0; i < n; i++)
		tmp[i] = 0.5 * (1 + erf((data[i] - mean(data)) / (sqrt(2) * sqrt(disp(data, mean(data))))));
	return tmp;
}