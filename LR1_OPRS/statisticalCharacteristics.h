#pragma once
#include <iostream>
#include <vector>
#include <cmath> 
using namespace std;

double disp(vector<double> data, double mean) { // ¬ычисление выборочной дисперсии // Sx^2 Sy^2
	int n = data.size();
	double sum = 0;
	for (int i = 0; i < n; i++)
		sum = sum + (data[i] - mean) * (data[i] - mean);
	return sum / (n - 1.0);
}

double mean(vector<double> data) { // ¬ычисление выборочного математического ожидани€ // x_ y_
	int n = data.size();
	double sum = 0;
	for (int i = 0; i < n; i++)
		sum = sum + data[i];
	return sum / n;
}

double S(double sx, double sy, int n, int m) {
	return sqrt((sx*(n-1) + sy*(m-1)) / (double) (n + m - 2.0));
}