/* leins, 02.04.2018 */
#include <cmath>
#include "point_class.h"
#include <GL/gl.h>
#include <GL/glut.h>

// #include "C:\Polytech\gandy\glut\glut.h"

void point_class::init(color_class c, float x0, float y0)
{
  x = x0;
  y = y0;
  color.color_init(c.get_r(), c.get_g(), c.get_b(), c.get_a());
} // end of function 

void point_class::change_x(float delta)
{
  x += delta;
} // end of func

void point_class::change_y(float delta)
{
  y += delta;
} // end of func

color_class point_class::get_color()
{
  return color;
}

void point_class::draw_point(double radius)
{
  float i;
  const float sepCnt = 20;
  const float pi = 3.14159265;

  glColor4f(color.get_r(), color.get_g(), color.get_b(), color.get_a());

  glBegin(GL_TRIANGLE_FAN);
  glVertex2d(x, y);
  for (i = 0; i < sepCnt; i++)
  {
	float angl = i / (sepCnt - 1) * 2.0 * pi;
	glVertex2d(x + radius * cos(angl), y + radius * sin(angl));
  }
  glEnd();
} // end of func

void point_class::change_step(float delta)
{
  color.change_alpha(delta);
} // end of func

