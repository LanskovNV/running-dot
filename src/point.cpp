/* leins, 02.04.2018 */
#include <cmath>
#include <GL/gl.h>
#include <GL/glut.h>
#include "point.h"


void point_t::update_pos(float dx, float dy)
{
    x += dx;
    y += dy;
}

float point_t::get_radius()
{
    return radius;
}

float point_t::get_alpha()
{
    return alpha;
}

float point_t::get_x()
{
    return x;
}

float point_t::get_y()
{
    return y;
}

void point_t::draw()
{
  float i;
  const float sepCnt = 20;
  const float pi = 3.14159265;

  glColor4f(color[0], color[1], color[2], alpha);

  glBegin(GL_TRIANGLE_FAN);
  glVertex2d(x, y);
  for (i = 0; i < sepCnt; i++)
  {
	float angl = i / (sepCnt - 1) * 2.0 * pi;
	glVertex2d(x + radius * cos(angl), y + radius * sin(angl));
  }
  glEnd();
} // end of func

void point_t::update()
{
    radius += delta_radius;
    alpha -= delta_alpha;
} // end of func

point_t& point_t::operator= (const point_t &p)
{
    x = p.x;
    y = p.y;
    radius = p.radius;
    alpha = p.alpha;

    return *this;
}
