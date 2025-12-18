#ifndef BALL_H
#define BALL_H
#include "object.h"
class ball : public object {
  // Information.
  double radius;
  // Total balls
  static long long totalBalls;

 public:
  // Getters
  pair<int, int> getPosition();
  double getRadius();
  // Detect Collision
  void collision();
  // Change shapre properties
  void drawShape();
  void deleteShape();
  void moveObject();
  void changeObjectType();
  void changeObjectColorTotality();
  void changeObjectColorContinuing();
};
#endif