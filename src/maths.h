
#ifndef MATHS_H
#define MATHS_H
#include <bits/stdc++.h>
using namespace std;
class vectorMaths {
 public:
  static double dotProduct(pair<double, double> first,
                           pair<double, double> second) {
    return first.first * second.first + second.second * first.second;
  }
  static pair<double, double> unitVector(pair<double, double> value) {
    double length = sqrt(pow(value.first, 2) + pow(value.second, 2));
    pair<double, double> unit;
    unit.first = value.first / length;
    unit.second = value.second / length;
    return unit;
  }
};

#endif