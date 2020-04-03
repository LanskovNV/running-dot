/* leins, 02.04.2018 */
#include "queue_class.h"

void queue_class::put(point_class p)
{
  queue.push_back(p);
  length += 1;
  if (head == NULL)
  {
	head = &queue.back();
	tail = head;
  }
  else
	tail++;
} // end of func

void queue_class::get()
{
  if (length > 0)
  {
	length -= 1;
	queue.erase(queue.begin());
	if (head == tail)
	{
	  head = NULL;
	  tail = NULL;
	}
	else
	  head++;
  }
} // end of func

void queue_class::track_init(float delta)
{
  if (tail != NULL)
  {
	std::vector<point_class>::iterator iter;

	if (tail->get_color().get_a() < 0)
	  queue.pop_back();

	for (iter = queue.begin(); iter != queue.end(); iter++)
	  iter->change_step(delta);
  }
} // end of func

void queue_class::put_track(double radius)
{
  std::vector<point_class>::iterator iter;

  for (iter = queue.begin(); iter != queue.end(); iter++)
	iter->draw_point(radius);

} // end of func


