#pragma once
#include <iostream>
#include <vector>
#include <cmath> 
#include <cstdlib>
#include "statisticalCharacteristics.h"
using namespace std;

void calc_max(double& max, double& curr)
{
	if (curr >= max)
	{
		max = curr;
	}
}

vector <double> sort_(vector <double> data) { // Сортировка вектора по возрастанию 
	int n = data.size();
	vector <double> tmp(n);
	for (int i = 0; i < n; i++)
	{
		tmp[i] = data[i];
		//cout << "i= " << tmp[i] << endl;
	}

	double temp = -1000000.0;
	for (int j = 1; j < n; j++)
		for (int i = 0; i < (n - 1); i++)
			if (tmp[i] > tmp[i + 1]) {
				temp = tmp[i];
				tmp[i] = tmp[i + 1];
				tmp[i + 1] = temp;
			}

	return tmp;
};

double KS(vector<double> data_) { // Вычисление значения статистики Колмогорова-Смирнова
	double max = 0;// max supremum
	double count_low = 0;
	double count_high = 0;
	double sum_low = 0;
	double sum_high = 0;

	int n = data_.size();
	double mean_ = mean(data_);
	double sigma = sqrt(disp(data_, mean_));

	vector <double> data(n);
	data = sort_(data_);

	for (int i = 0; i < (n - 1); i++)
	{
		if (data[i] != data[i + 1])
		{
			count_high++;
			sum_low = abs(0.5 * (1 + erf((data[i] - mean_) / (sqrt(2) * sigma))) - (count_low / (double)n));
			sum_high = abs((count_high / (double)n) - 0.5 * (1 + erf((data[i] - mean_) / (sqrt(2) * sigma))));
			calc_max(sum_high, sum_low);// Максимум сравнения записываем в sum_high(текущий Sup)
			calc_max(max, sum_high);
			count_low = count_high;
			if (i == (n - 2))
			{
				count_high++;
				sum_low = abs(0.5 * (1 + erf((data[i] - mean_) / (sqrt(2) * sigma))) - (count_low / n));
				sum_high = abs((count_high / n) - 0.5 * (1 + erf((data[i] - mean_) / (sqrt(2) * sigma))));
				calc_max(sum_high, sum_low);// Максимум сравнения записываем в sum_high
				calc_max(max, sum_high);
				count_low = count_high;
			}
		}
		else
		{
			count_high++;
			if (i == (n - 2))
			{
				count_high++;
				sum_low = abs(0.5 * (1 + erf((data[i] - mean_) / (sqrt(2) * sigma))) - (count_low / (double)n));
				sum_high = abs((count_high / (double)n) - 0.5 * (1 + erf((data[i] - mean_) / (sqrt(2) * sigma))));
				calc_max(sum_high, sum_low);// максимум сравнения записываем в sum_high
				calc_max(max, sum_high);
				count_low = count_high;
			}
		}
	}
	return max;
}