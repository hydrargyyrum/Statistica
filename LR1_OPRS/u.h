#pragma once
#include <iostream>
#include <vector>
#include <cmath> 
#include <cstdlib>
#include "statisticalCharacteristics.h"

vector <double> sortt(vector <double> data) {
	int n = data.size();
	vector <double> tmp(n);
	for (int i = 0; i < n; i++)
		tmp[i] = data[i];

	double temp = 0.0;
	for (int j = 1; j < n; j++)
		for (int i = 0; i < (n - 1); i++)
			if (tmp[i] > tmp[i + 1]) {
				temp = tmp[i];
				tmp[i] = tmp[i + 1];
				tmp[i + 1] = temp;
			}
	return tmp;
};

vector<double> R(vector <double> data_) { 
	int n = data_.size();
	vector <double> rang(n);
	vector <double> data = sortt(data_);

	int i_begin = -1;
	int i_end = -1;
	double count = 1;

	//База
	for (int i = 0; i < n; i++) rang[i] = (double)i + 1.0;

	//Коррекция
	int i = 0;
	while (i < (n - 1)) {
		for (int j = i + 1; j < n; j++) {
			if (data[i] == data[j])
			{
				i_begin = i;
				i_end = j;
				count++;
			}
			else continue;
		}
		if (count > 1) {
			double tmp = 0;
			double new_rang = 0;
			int i_curr = i_begin;
			while (i_curr <= i_end)
			{
				tmp = rang[i_curr] + tmp;
				i_curr++;
			}
			new_rang = (double)tmp / (double)count;
			for (int j = 0; j < count; j++)
			{
				rang[i_begin] = new_rang;
				i_begin++;
			}
			i = i + count;
			count = 1;
		}
		else i++;
	}
	return rang;
}

double Ri(vector <double> data, vector <double> rang, vector <double> datasum_) {
	int n = data.size();
	int ms = datasum_.size();
	vector < double> rang_curr(n);
	vector < double> datasum(ms);
	datasum = sortt(datasum_);

	for (int i = 0; i < n; i++) 
		for (int j = 0; j < ms; j++)
			if (data[i] == datasum[j]) {
				rang_curr[i] = rang[j];
				continue;
			}
	
	double sum = 0;
	for (int i = 0; i < n; i++) sum = sum + rang_curr[i];
	return sum;
}

double u(vector <double> data1, vector<double> data2) {
	int n = data1.size();
	int m = data2.size();
	vector <double> datasum(n + m);
	vector <double> rang(n + m);
	datasum = data1;
	for (int i = 0; i < m; i++) datasum.push_back(data2[i]);
	double R1 = Ri(data1,R(datasum),datasum);
	double R2 = Ri(data2, R(datasum), datasum);
	cout << "R1=" << R1 << endl;
	cout << "R2=" << R2 << endl;
	double U1 = (double)n * (double)m + (double)n * ((double)n + 1.0) / 2.0 - R1;
	double U2 = (double)n * (double)m + (double)m * ((double)m + 1.0) / 2.0 - R2;
	cout << "U1= " << U1 << endl;
	cout << "U2= " << U2 << endl;
	cout << "U1+U2= " << U1 + U2 << endl;
	cout << endl;
	//cout << "nm= " << m * n << endl;
	if (U1 >= U2) return U2;
	else return U1;
}

double z(int u, vector <double> data1, vector<double> data2) {
	int n = data1.size();
	int m = data2.size();
	double mu = (double)n * ((double)m + (double)n + 1.0) / 2.0;
	double sigma_mu = sqrt((double)m * (double)n * ((double)m + (double)n + 1.0) / 12.0);
	return (u - mu) / sigma_mu;
}