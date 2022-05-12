#include "Queue.h"
#include <vector>

Queue::Queue(int max_len) : max_len(max_len), queue(0,0), now(0)
{

}
bool Queue::isEmpty()
{
	if (now == 0)
		return 1;
	else
		return 0;
}
bool Queue::isFull()
{
	if (now == max_len)
		return 1;
	else
		return 0;
}
void Queue::EnQueue(int x)
{
	if (!isFull())
	{
		queue.push_back(x);
		now++;
	}
}
int Queue::DeQueue()
{
	now--;
	int out = 0;
	out = queue[0];
	queue.erase(queue.begin());
	return out;
}
const int Queue::size()
{
	return max_len;
}




Priority_Queue::Priority_Queue(int max_len) : max_len(max_len+1), queue(0), now(0)
{

}
bool Priority_Queue::isEmpty()
{
	if (now == 0)
		return 1;
	else
		return 0;
}
bool Priority_Queue::isFull()
{
	if (now == max_len - 1)
		return 1;
	else
		return 0;
}
void Priority_Queue::EnQueue(int x, int priority)
{
	if (!isFull())
	{
		prior tmp;
		tmp.x = x;
		tmp.priority = priority;
		bool last = 1;
		for (int i = 0; i < now; i++)
		{
			if (priority < queue[i].priority)
			{
				queue.insert(queue.begin()+i, tmp);
				last = 0;
				break;
			}
		}
		if (last)
			queue.push_back(tmp);
		now++;
	}
}
int Priority_Queue::DeQueue()
{
	now--;
	int out = queue[0].x;
	queue.erase(queue.begin());
	return out;
}
const int Priority_Queue::size()
{
	return max_len;
}
