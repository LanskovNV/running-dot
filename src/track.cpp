/* leins, 02.04.2018 */
#include "track.h"

track::track(float x, float y)
{
    p = point_t(x, y);
}

void track::move(float new_x, float new_y)
{
    tail.push_back(p);
    p = point_t(p.get_x() + new_x, p.get_y() + new_y);
}

void track::draw()
{
    p.draw();
    for (auto points : tail)
        points.draw();
}

void track::update()
{
    std::list<point_t>::iterator it;

    for (it = tail.begin(); it != tail.end(); it++)
        it->update();
    if (tail.size() != 0 && tail.front().get_alpha() == 0)
        tail.pop_front();
}



