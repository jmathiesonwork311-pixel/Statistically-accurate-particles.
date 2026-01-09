#include "ball.h"
long long totalBalls = 0;

void ball::applyGravity() { velocity.second -= 9.8; }
void ball::changeObjectColorContinuing() {}
void ball::changeObjectColorTotality() {}
void ball::collision(ball other) {
  // Learned from OPENGL page
  // https://learnopengl.com/In-Practice/2D-Game/Collisions/Collision-detection
  pair<double, double> positionOther = other.getPosition();
  double radiusOther = other.getRadius();
  bool collidingCircles = sqrt(pow(position.first - positionOther.first, 2) +
                               pow(position.second - positionOther.second,
                                   2)) <= radius + radiusOther;
  if (collidingCircles) {
  }
  return;
}
void ball::updateVelocity() {
  velocity.second -= 5;
  // https://en.wikipedia.org/wiki/Elastic_collision#Two-dimensional
}
ball::ball() { generateBall(); }
void ball::generateBall() {
  const int segments = 16;
  const double PI = 3.14159265359;
  vertices.push_back(0.0f);
  vertices.push_back(0.0f);

  for (int i = 0; i <= segments; i++) {
    float angle = 2.0f * PI * i / segments;
    vertices.push_back(radius * cos(angle));
    vertices.push_back(radius * sin(angle));
  }
  glGenVertexArrays(1, &VAO);
  glGenBuffers(1, &VBO);

  glBindVertexArray(VAO);

  glBindBuffer(GL_ARRAY_BUFFER, VBO);
  glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(float),
               vertices.data(), GL_STATIC_DRAW);
  glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 2 * sizeof(float), (void*)0);
  glEnableVertexAttribArray(0);

  glBindVertexArray(0);
}
void ball::deleteShape() {
  if (VAO != 0) {
    glDeleteVertexArrays(1, &VAO);
    glDeleteBuffers(1, &VBO);
    VAO = 0;
    VBO = 0;
  }
}
void ball::drawShape() {
  glUseProgram(shader);

  glUniform2f(glGetUniformLocation(shader, "offset"), position.first,
              position.second);

  glBindVertexArray(VAO);
  glDrawArrays(GL_TRIANGLE_FAN, 0, vertices.size() / 2);
  glBindVertexArray(0);
}
std::pair<double, double> ball::getPosition() { return position; }
std::pair<double, double> ball::getVelocity() { return velocity; }
double ball::getRadius() { return radius; }
void ball::moveObject() {
  position.first += velocity.first;
  position.second += velocity.second;
}
ball::~ball() { deleteShape(); }