#ifndef BALL_H
#define BALL_H

#include <cmath>

#include "maths.h"
#include "object.h"
class ball : public object {
  // Information.
  double radius = 0.005;
  // Static variables for ID, total balls, and to search for collisions.
  static long long totalBalls;
  static long long ballId;
  static vector<ball*> otherBalls;
  unsigned int VAO = 0;
  unsigned int VBO = 0;
  long long id;
  pair<double, double> force = {0, 0};
  pair<double, double> velocity = {0, 0};
  pair<double, double> position = {0, 0};

 public:
  // Getters
  pair<double, double> getPosition() const override;
  double getRadius();
  ball();
  // Detect Collision
  void changePosition(double x, double y);
  void collision() override;
  void updateVelocity();
  // Change shapre properties
  void drawShape() const override;
  void deleteShape();
  void moveObject() override;
  void changeObjectType() override;
  void changeObjectColorTotality() const override;
  void changeObjectColorContinuing() const override;
  void applyGravity();
  void generateBall();
  pair<double, double> getVelocity();
  ~ball();
};
#endif