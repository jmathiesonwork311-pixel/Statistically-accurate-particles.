#ifndef OBJECT_H
#define OBJECT_H
#include <GL/glut.h>
#include <bits/stdc++.h>

#include <iostream>

using namespace std;
class object {
 protected:
  pair<double, double> position, velocity;
  tuple<int, int, int> color;

 private:
 public:
  void generateBall();
  virtual pair<double, double> getPosition() const = 0;
  virtual void collision() = 0;
  virtual void drawShape() const = 0;
  virtual void deleteShape() = 0;
  virtual void moveObject() = 0;
  virtual void changeObjectType() = 0;
  virtual void changeObjectColorTotality() const = 0;
  virtual void changeObjectColorContinuing() const = 0;
};
#endif
