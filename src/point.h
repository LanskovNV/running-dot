#ifndef _POINT_H_
#define _POINT_H_
/* leins, 02.04.2018 */

class point_t
{  
private:
  float x;
  float y;
  float alpha;
  float radius;

  constexpr static float color[3] = {1, 0, 0}; // RGB
  constexpr static float default_radius = 0.025;
  constexpr static float default_alpha = 1;
  const float delta_radius = 0.0005;
  const float delta_alpha = 0.005;

public:
  point_t() : x(0), y(0), alpha(default_alpha), radius(default_radius) {};
  point_t(float x0, float y0) : x(x0), y(y0), alpha(default_alpha), radius(default_radius) {};
  point_t(const point_t &p) :
      x(p.x),
      y(p.y),
      alpha(p.alpha),
      radius(p.radius) {};

  void update_pos(float, float);
  float get_alpha() { return alpha; };
  float get_x() { return x; };
  float get_y() { return y; };
  float get_radius() { return radius; };
  void draw();
  void update();

  point_t& operator= (const point_t&);
};

#endif // _POINT_H_
