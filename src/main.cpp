/* leins, 21.03.2018 */
#include <iostream>
#include <GL/gl.h>
#include <GL/glut.h>
// #include "C:\Polytech\gandy\glut\glut.h"
#include "color_class.h"
#include "queue_class.h"
#include "timer_class.h"


using namespace std;

// global objects
timer_class timer_g;
color_class color_g;
point_class point_g;
queue_class track_g;

// macros
#define H 800
#define W 800
#define DELTA_A 1.0
#define RAD 0.03
#define SPEED 6.0 // 3.0

void Keyboard(unsigned char key, int x, int y)
{
  float s = 0.02; // step size

  if (key == 27)
    exit(0);
  if (key == 'w')
  {
	track_g.put(point_g);
	point_g.change_y(s);
  }
  if (key == 's')
  {
	track_g.put(point_g);
	point_g.change_y(-s);
  }
  if (key == 'a')
  {
	track_g.put(point_g);
	point_g.change_x(-s);
  }
  if (key == 'd')
  {
	track_g.put(point_g);
	point_g.change_x(s);
  }
}// End of Keyboard function 

void Display(void)
{
  timer_g.timer_update_frame();

  glClearColor(0.3, 0.5, 0.7, 1);
  glClear(GL_COLOR_BUFFER_BIT);

  point_g.draw_point(RAD);
  track_g.track_init(SPEED * timer_g.delta);
  track_g.put_track(RAD);

  glFinish();
  glutSwapBuffers();
  glutPostRedisplay();
}// End of Display function 

int main(int argc, char *argv[])
{
  // track init 
  float x0 = 0, y0 = 0, r = 1, g = 0, b = 0, a = 1;

  color_g.color_init(r, g, b, a);
  point_g.init(color_g, x0, y0);

  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE);

  glutInitWindowPosition(0, 0);
  glutInitWindowSize(H, W);
  glutCreateWindow("running dot");

  glutDisplayFunc(Display);
  glutKeyboardFunc(Keyboard);

  glEnable(GL_BLEND);
  glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

  timer_g.timer_init();
  glutMainLoop();
  return 0;
}// end of main
