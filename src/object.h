#ifndef OBJECT_H
#define OBJECT_H
#include <bits/stdc++.h>

#include <iostream>

using namespace std;
class object {
 protected:
  pair<double, double> position, velocity;
  tuple<int, int, int> color;

 private:
 public:
  virtual void collision() const = 0;
  virtual void drawShape() const = 0;
  virtual pair<int, int> getPosition() const = 0;
  virtual void deleteShape() const = 0;
  virtual void moveObject() const = 0;
  virtual void changeObjectType() const = 0;
  virtual void changeObjectColorTotality() const = 0;
  virtual void changeObjectColorContinuing() const = 0;
};
#endif
