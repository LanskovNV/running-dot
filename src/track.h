#pragma once
#ifndef _QUEUE_CLASS
#define _QUEUE_CLASS

/* leins, 02.04.2018 */
#include <list>
#include "point.h"

class track
{
private:
    point_t p;
    std::list<point_t> tail;

public:
    track() {};
    track(float, float);

    void move(float new_x, float new_y);
    void draw();
    void update();
};

#endif
