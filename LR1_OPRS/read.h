#pragma once
#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

vector <double> data_(string name) {
    ifstream input(name);

    double ch;
    int Count = 0;

    while (input >> ch)
        Count++;
    input.close();

    vector <double> data(Count);

    ifstream file(name);
    for (int i = 0; i < Count; i++) {
        file >> data[i];
    }

    return data;
}
