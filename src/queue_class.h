#pragma once
#ifndef _QUEUE_CLASS
#define _QUEUE_CLASS

/* leins, 02.04.2018 */
#include <vector>
#include <cstdlib>
#include "point_class.h"
class queue_class : public point_class
{
private:
  int length;
  point_class *head;
  point_class *tail;
  std::vector<point_class> queue;

public:
  queue_class() : length(0), head(NULL), tail(NULL) {}

  void put(point_class p);
  void get();
  void track_init(float delta);
  void put_track(double radius);
};

#endif
