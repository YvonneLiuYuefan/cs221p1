//LinkedListQueue.cpp
#ifndef _LINKEDLISTQUEUE_CPP
#define _LINKEDLISTQUEUE_CPP

#include "LinkedListQueue.hpp"
#include <cstdlib> //for NULL
#include <cassert>
#include <iostream>
LinkedListQueue::LinkedListQueue()
{
  head = NULL;
  tail = NULL;
  size = 0;
}

void LinkedListQueue::add(MazeState *elem)
{
  node *temp = new node;
  temp->data = elem;
  if (size == 0) {
    head = temp;
    tail = temp;
  } else {
    tail->next = temp;
    tail = temp;
  }
  size++;
}

MazeState *LinkedListQueue::remove()
{
  assert(!is_empty());
  MazeState *ret = head->data;
  node *temp = new node;
  temp = head;
  head = head->next;
  delete temp;
  size--;
}

bool LinkedListQueue::is_empty()
{
  return (size == 0);
}

LinkedListQueue::~LinkedListQueue()
{
  while(size > 0)
    remove();
}

#endif

