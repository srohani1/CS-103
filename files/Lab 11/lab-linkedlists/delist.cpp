#include <iostream>
#include "delist.h"
using namespace std;
// Constructs an empty Double-Ended List
    DEList::DEList()
    {
    	head = NULL;
    	tail = NULL;
    	size1 = 0;
    }
    // Destructor to clean-up memory of current list
    DEList::~DEList()
    {
    	while(head != NULL)
    	{
    		DEItem* temp;
    		temp =  head;
    		head = head->next;
    		delete temp;
    	}
    }
    // returns a Boolean 'true' if the list is empty
    bool DEList::empty()
    {
    	if (head == NULL && tail == NULL)
			{
				return true;
			} 
		else 
		return false;	
    }
    // returns number of items in the list
    int DEList::size()
    {
    	return size1;
    }
    // returns front item or -1 if empty list
    int DEList::front()
    {
    	if (size() == 0)
    	{
    		return -1;
    	}
    	else 
    		return head->val;
    }
    // returns back item or -1 if empty list
    int DEList::back()
    {
    	if(size() == 0)
    	{
    		return -1;
    	}
    	else
    		return tail->val;
    }
    // Adds a new integer to the front of the list
    void DEList::push_front(int new_val)
    {
   		DEItem* newItem = new DEItem;
   		newItem->val = new_val;
   		if (head == NULL)
   		{
   			newItem->next = NULL; 
   			newItem->prev = NULL;
   			head = newItem;
   			tail = newItem;
   			size1++;
   		}
   		else
   		{
   			head->prev = newItem;
   			newItem->next = head; 
   			newItem->prev = NULL;
   			head = newItem;
    		size1++;
   		}
    }
    // Adds a new integer to the back of the list
    void DEList::push_back(int new_val)
    {
    	DEItem* newItem = new DEItem;
   		newItem->val = new_val;
   		if (tail == NULL)
   		{
   			newItem->next = NULL;
   			newItem->prev = NULL;
   			tail = newItem;
   			head = newItem;
   			size1++;
   		}
   		else
   		{
   			tail->next = newItem;
   			newItem->next = NULL; 
   			newItem->prev = tail;
   			tail = newItem;
    		size1++;
   		}
    }
    // Removes the front item of the list (if it exists)
    void DEList::pop_front()
    {
    	if(size() == 0)
    	{
    		return;
    	}
    	DEItem* temp = head;
    	head = head->next;
    	if(head != NULL) 
    	{
    		head->prev = NULL;
    	} else 
    	{
    		tail = NULL;
    	}
    	size1--;
    	delete temp;
    }
    // Removes the back item of the list (if it exists)
    void DEList::pop_back()
    {
    	if(size() == 0)
    	{
    		return;
    	}
    	DEItem* temp = tail;
    	tail = tail->prev;
    	if(tail != NULL) 
    	{
    		tail->next = NULL;
    	} else 
    	{
    		head = NULL;
    	}
    	size1--;
    	delete temp;
    }
