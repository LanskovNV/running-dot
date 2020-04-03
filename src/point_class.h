#pragma once
#ifndef _POINT_CLASS
#define _POINT_CLASS
#include "color_class.h"
/* leins, 02.04.2018 */

class point_class : public color_class
{  
private:
  float x;
  float y;
  color_class color;

public:
  void change_x(float delta);
  void change_y(float delta);
  color_class get_color();
  void init(color_class c, float x0, float y0);
  void draw_point(double radius);
  void change_step(float delta);
};

#endif