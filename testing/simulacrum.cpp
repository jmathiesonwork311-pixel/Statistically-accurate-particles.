#include <GL/glut.h>

#include "../src/ball.h"
#include "../src/object.h"
// 1. Create the ball object globally so the display function can see it
ball a, b;
void generateBall() {}
void display() {
  glClear(GL_COLOR_BUFFER_BIT);

  a.drawShape();  // Draw the current state
  glFlush();
}
void update(int value) {
  glClear(GL_COLOR_BUFFER_BIT);
  a.applyGravity();
  b.applyGravity();
  a.collision();

  a.updateVelocity();
  a.drawShape();
  b.collision();
  b.updateVelocity();
  b.drawShape();
  glutTimerFunc(16, update, 0);

  glFlush();
}

int main(int argc, char** argv) {
  b.changePosition(0.003, 1);
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
  glutInitWindowSize(1000, 1000);
  glutCreateWindow("OpenGL Ball Simulation");

  glClearColor(0.0, 0.0, 0.0, 1.0);  // Black background

  // 3. Pass the name of the function to be called for drawing
  glutDisplayFunc(display);
  glutTimerFunc(1000, update, 0);
  glutMainLoop();
  return 0;
}