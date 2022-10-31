#pragma once
#include <iostream>
#include <vector>
#include <cmath> 
#include <cstdlib>
#include "statisticalCharacteristics.h"
using namespace std;

void update_max(double& max, double& curr)
{
	if (curr >= max)
	{
		max = curr;
	}
}

double KS(vector<double> data) { // Вычисление значения статистики Колмогорова-Смирнова
	double max = 0;// max supremum
	double curr = 0;// current supremum
	double count_low = 0;
	double count_high = 0;
	double sum_low = 0;
	double sum_high = 0;
	int n = data.size();
	double mean_ = mean(data);
	double sigma = sqrt(disp(data, mean_));
	for (int i = 0; i < n - 1; i++)
	{
		if (data[i] != data[i + 1])
		{
			count_high++;
			sum_low = abs(0.5 * (1 + erf((data[i] - mean_) / (sqrt(2) * sigma))) - (count_low / n));
			sum_high = abs((count_high / n) - 0.5 * (1 + erf((data[i] - mean_) / (sqrt(2) * sigma))));
			update_max(sum_high, sum_low);// Максимум сравнения записываем в sum_high(текущий Sup)
			update_max(max, sum_high);
			count_low = count_high;
			if (i == (n - 2))
			{
				count_high++;
				sum_low = abs(0.5 * (1 + erf((data[i] - mean_) / (sqrt(2) * sigma))) - (count_low / n));
				sum_high = abs((count_high / n) - 0.5 * (1 + erf((data[i] - mean_) / (sqrt(2) * sigma))));
				update_max(sum_high, sum_low);// Максимум сравнения записываем в sum_high
				update_max(max, sum_high);
				count_low = count_high;
			}
		}
		else
		{
			count_high++;
			if (i == (n - 2))
			{
				count_high++;
				sum_low = abs(0.5 * (1 + erf((data[i] - mean_) / (sqrt(2) * sigma))) - (count_low / n));
				sum_high = abs((count_high / n) - 0.5 * (1 + erf((data[i] - mean_) / (sqrt(2) * sigma))));
				update_max(sum_high, sum_low);// максимум сравнения записываем в sum_high
				update_max(max, sum_high);
				count_low = count_high;
			}
		}
	}
	return max;
}