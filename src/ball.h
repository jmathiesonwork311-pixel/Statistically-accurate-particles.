#ifndef BALL_H
#define BALL_H

#include <glad/glad.h>

#include <cmath>

#include "object.h"
class ball : public object {
  // Information.
  double radius = 0.2;
  // Total balls
  static long long totalBalls;
  unsigned int VAO = 0;
  unsigned int VBO = 0;
  vector<float> vertices;

 public:
  // Getters
  pair<double, double> getPosition();
  double getRadius();
  ball();
  // Detect Collision
  void collision(ball other);
  void updateVelocity();
  // Change shapre properties
  void drawShape();
  void deleteShape();
  void moveObject();
  void changeObjectType();
  void changeObjectColorTotality();
  void changeObjectColorContinuing();
  void applyGravity();
  void generateBall();
  ~ball();
};
#endif