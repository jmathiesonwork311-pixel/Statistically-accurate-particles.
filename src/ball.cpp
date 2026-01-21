#include "ball.h"
// Static variables, total balls,
long long ball::totalBalls = 0;
long long ball::ballId = 0;

vector<ball*> ball::otherBalls = {};
#define PI 3.146;
void ball::applyGravity() { force.second -= 9.8 * 1; }
void ball::changeObjectType() { return; }
void ball::changeObjectColorContinuing() const {}
void ball::changeObjectColorTotality() const {}
void ball::changePosition(double x, double y) { position = {x, y}; }
void ball::collision() {
  const double KN = 100000.0;
  for (auto x : otherBalls) {
    if (x->id != id) {
      pair<double, double> distVector = {x->position.first - position.first,
                                         x->position.second - position.second};
      double length =
          sqrt(pow(distVector.first, 2) + pow(distVector.second, 2));
      double minimumDist = x->radius + radius;
      if (length == 0) {
        length = 0.0001;
        distVector = {0, 0.0001};
      }
      if (minimumDist < length) continue;

      if (minimumDist == 0) minimumDist = 0;
      double overlap = -length + minimumDist;
      double fn = KN * overlap * 0.1;
      pair<double, double> velocity = {x->velocity.first - velocity.first,
                                       x->velocity.second - velocity.second};
      pair<double, double> contactNormal = vectorMaths::unitVector(distVector);
      pair<double, double> collisionForce = {fn * contactNormal.first,
                                             fn * contactNormal.second};
      force.first -= collisionForce.first;
      force.second -= collisionForce.second;
    }
  }
  // Learned from OPENGL page
  // https://learnopengl.com/In-Practice/2D-Game/Collisions/Collision-detection
  return;
}
void ball::updateVelocity() {
  velocity.first += (force.first / 1) * 0.016;
  velocity.second += (force.second / 1) * 0.016;
  position.first += velocity.first * 0.016;
  position.second += velocity.second * 0.016;
  if (position.second < radius - 1)
    position.second = -1.0 + radius, velocity.second *= -0.1;
  if (position.first > -radius + 1) {
    position.first = 1.0 - radius;
    velocity.first *= -0.1;
  } else if (position.first < radius - 1)
    position.first = radius - 1.0, velocity.first *= -0.1;

  force = {0, 0};
  // https://en.wikipedia.org/wiki/Elastic_collision#Two-dimensional
}
ball::ball() {
  // Declare position. Then velcity.
  position = {0, 0};
  velocity = {0, 0};
  // Increment static values.
  id = ballId++;
  totalBalls++;
  otherBalls.push_back(this);
  drawShape();
}
void ball::generateBall() {}
void ball::deleteShape() {}
void ball::drawShape() const {
  // Changing GL_ to GL_POLYGON to create a solid circle
  glBegin(GL_POLYGON);
  glColor3f(1.0, 0.0, 0.0);  // Red color

  int amountOfLines = 40;  // The more lines, the smoother the circle

  for (int i = 0; i < amountOfLines; i++) {
    // Calculate the angle for this point
    float angle = 2.0f * 3.1415926f * i / amountOfLines;

    // Calculate x and y based on the angle
    float x = radius * cosf(angle) + position.first;
    float y = radius * sinf(angle) + position.second;

    glVertex2f(x, y);
  }

  glEnd();
  glFlush();
}
std::pair<double, double> ball::getPosition() const { return position; }
std::pair<double, double> ball::getVelocity() { return velocity; }
double ball::getRadius() { return radius; }
void ball::moveObject() {
  position.first += velocity.first;
  position.second += velocity.second;
}
ball::~ball() { deleteShape(); }