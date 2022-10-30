#include <iostream>
#include "ks.h"
#include "chi2.h"
#include "t.h"
#include "read.h"
#include "statisticalCharacteristics.h"
using namespace std;

void main() {

	vector <double> dataLR1 = data_("f_LR1.txt");
	vector <double> dataLR2_2 = data_("f_LR2_2.txt");
	vector <double> dataLR2_4 = data_("f_LR2_4.txt");
	vector <double> dataLR2_10 = data_("f_LR2_10.txt");

	//LR1
	cout << "KS=" << KS(F(dataLR1), F0(dataLR1)) << endl;
	cout << "KS2=" << KS(F(dataLR2_2), F0(dataLR2_2)) << endl;
	cout << "KS4=" << KS(F(dataLR2_4), F0(dataLR2_4)) << endl;
	cout << "KS10=" << KS(F(dataLR2_10), F0(dataLR2_10)) << endl << endl;
	cout << "CHI2=" << chi2(dataLR1, sqrt(dataLR1.size())) << endl;

	//LR2
	cout << "T2-10=" << t(dataLR2_2, dataLR2_10) << endl;
	cout << "T4-10=" << t(dataLR2_4, dataLR2_10) << endl;
}