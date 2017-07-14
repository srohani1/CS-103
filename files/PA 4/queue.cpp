/* 
queue.cpp
Author: Alec Lord
Short description of this file:
*/
#include "queue.h"
// constructor. maxlen must be as large as the total number
// of Locations that will ever be entered into this Queue.
// this is complete, you don't need to change it.
Queue::Queue(int maxlen) 
{
   contents = new Location[maxlen];
   head = 0;
   tail = 0;
}
// destructor. releases resources. C++ will call it automatically.
// this is complete, you don't need to change it.
Queue::~Queue() 
{
   delete[] contents;
}
// insert a new Location at the end/back of our list   
void Queue::push(Location loc) 
{
	contents[tail] = loc;
	tail = tail + 1;   
}
// return and "remove" the oldest Location not already extracted
Location Queue::pop() 
{
   Location temp = contents[head];
   head = head + 1;
   return temp;
}
// is this Queue empty? (did we extract everything added?)
bool Queue::is_empty() 
{
   if (head == tail)
   {
   	return true;
   }
   else 
   {
   	return false;
   }
}
