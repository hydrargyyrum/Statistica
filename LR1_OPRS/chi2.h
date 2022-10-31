#pragma once
#include <iostream>
#include <vector>
#include <cmath> 
#include <cstdlib>

#include "statisticalCharacteristics.h"
using namespace std;

vector <double> sort(vector <double> data) { // Сортировка вектора по возрастанию 
	int n = data.size();

	vector <double> tmp(n);
	for (int i = 0; i < n; i++)
	{
		tmp[i] = data[i];
		//cout << "i= " << tmp[i] << endl;
	}

	double temp = -10000;
	for (int i = 0; i < (n - 1); i++)
	{
		if (tmp[i] >= tmp[i + 1]) {
			temp = tmp[i + 1];
			tmp[i + 1] = tmp[i];
			tmp[i] = temp;
		}
	}
	return tmp;
};

vector <double> ni(vector <double> data, int N) { // Вычисление эмпирической 
	int n = data.size();
	vector <double> tmp(N);
	double length = (double)(data[n - 1] - data[0]) / (double)N;

	int k = 0;
	for (int k = 0; k < N; k++) {
		int count = 0; // Количество попаданий в k-ый интервал;
		for (int i = 0; i < n; i++)
		{
			if (k != N - 1)
				if ((data[i] >= data[0] + k * length) && (data[i] < data[0] + (k + 1) * length)) count++;
				else continue;
			else
				if ((data[i] >= data[0] + k * length) && (data[i] <= data[0] + (k + 1) * length)) count++;
				else continue;
		}

		tmp[k] = (double)count / (double)n;
		//cout << "emp = " << tmp[k] << endl;
	}
	return tmp;
}

vector <double> npi(vector <double> data, int N) { // Вычисление теоретической
	int n = data.size();
	double mean_ = mean(data);
	double disp_ = disp(data, mean_);
	vector <double> tmp(N);
	double lambda = 1.0 / mean(data);
	double length = (double)(data[n - 1] - data[0]) / (double)N;
	for (int k = 0; k < N; k++) {
	tmp[k] = 0.5 * (erf((data[0] + (k + 1) * length - mean_) / (sqrt(2) * sqrt(disp_))) -
		erf((data[0] + k * length - mean_) / (sqrt(2) * sqrt(disp_))));
		//cout << "teor = " << tmp[k] << endl;
	}
	return tmp;
}

double chi2(vector<double> data, int N) { // Вычисление значения статистики хи-квадрат
	int n = data.size();
	vector <double> data_new(n);
	data_new = sort(data);

	vector <double> ni_(N);
	vector <double> npi_(N);

	ni_ = ni(data_new, N);
	npi_ = npi(data_new, N);
	double sum = 0;
	for (int i = 0; i < N; i++)
		sum = sum + (ni_[i] - npi_[i]) * (ni_[i] - npi_[i]) / npi_[i];
	return sum * (double)N;
}

