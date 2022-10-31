#include <iostream>
#include "ks.h"
#include "chi2.h"
#include "t.h"
#include "f.h"
#include "read.h"
#include "statisticalCharacteristics.h"
using namespace std;

void main() {

	vector <double> dataLR1 = data_("f_LR1.txt");
	vector <double> dataLR2_2 = data_("f_LR2_2.txt");
	vector <double> dataLR2_4 = data_("f_LR2_4.txt");
	vector <double> dataLR2_10 = data_("f_LR2_10.txt");

	////LR1
	cout << "KS=" << KS(dataLR1) << endl;
	//cout << "CHI2=" << chi2(dataLR1, sqrt(dataLR1.size())) << endl;

	////LR2
	cout << "KS=" << KS(dataLR2_2) << endl;
	cout << "KS=" << KS(dataLR2_4) << endl;
	cout << "KS=" << KS(dataLR2_10) << endl;
	//cout << "CHI2_2=" << chi2(dataLR2_2, 10) << endl;
	//cout << "CHI2_4=" << chi2(dataLR2_4, 10) << endl;
	//cout << "CHI2_10=" << chi2(dataLR2_10, 10) << endl;
	//cout << "T2-10=" << t(dataLR2_2, dataLR2_10) << endl;
	//cout << "T4-10=" << t(dataLR2_4, dataLR2_10) << endl;
	//cout << "F2-10=" << f(dataLR2_2, dataLR2_10) << endl;
	//cout << "F4-10=" << f(dataLR2_4, dataLR2_10) << endl;
}