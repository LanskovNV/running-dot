/* leins, 21.03.2018 */
#include <iostream>
#include <GL/gl.h>
#include <GL/glut.h>
#include "track.h"

using namespace std;

track track_g;

// macros
#define H 800
#define W 800

void Keyboard(unsigned char key, int x, int y)
{
  float s = 0.03; // step size

  if (key == 27)
    exit(0);
  if (key == 'w')
      track_g.move(0, s);
  if (key == 's')
      track_g.move(0, -s);
  if (key == 'a')
      track_g.move(-s, 0);
  if (key == 'd')
      track_g.move(s, 0);
}// End of Keyboard function 

void Display(void)
{
  glClearColor(0.3, 0.5, 0.7, 1);
  glClear(GL_COLOR_BUFFER_BIT);

  track_g.update();
  track_g.draw();

  glFinish();
  glutSwapBuffers();
  glutPostRedisplay();
}// End of Display function 

int main(int argc, char *argv[])
{
  track_g = track(0, 0);

  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE);

  glutInitWindowPosition(0, 0);
  glutInitWindowSize(H, W);
  glutCreateWindow("running dot");

  glutDisplayFunc(Display);
  glutKeyboardFunc(Keyboard);

  glEnable(GL_BLEND);
  glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

  glutMainLoop();
  return 0;
}// end of main
