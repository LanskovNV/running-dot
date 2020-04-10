/* leins, 21.03.2018 */
#include <iostream>
#include <GL/gl.h>
#include <GL/glut.h>
#include "track.h"

track track_g = track(0, 0);

void Special(int key, int x, int y)
{
    float s = 0.03 + 0 * x + 0 * y; // step size

    switch(key)
    {
    case GLUT_KEY_UP:
        track_g.move(0, s);
        break;
    case GLUT_KEY_DOWN:
        track_g.move(0, -s);
        break;
    case GLUT_KEY_LEFT:
        track_g.move(-s, 0);
        break;
    case GLUT_KEY_RIGHT:
        track_g.move(s, 0);
        break;
    }
}

void Keyboard(unsigned char key, int x, int y)
{
    if (key + 0*x + 0*y == 27) // escape
        exit(0);
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
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE);

  glutInitWindowPosition(0, 0);
  glutInitWindowSize(800, 800); // W, H
  glutCreateWindow("running dot");

  glutSpecialFunc(Special);
  glutDisplayFunc(Display);
  glutKeyboardFunc(Keyboard);

  glEnable(GL_BLEND);
  glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

  glutMainLoop();
  return 0;
}// end of main
