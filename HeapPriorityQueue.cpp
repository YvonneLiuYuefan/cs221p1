//HeapPriorityQueue.cpp
#ifndef _HEAPPRIORITYQUEUE_CPP
#define _HEAPPRIORITYQUEUE_CPP

#include "HeapPriorityQueue.hpp"
#include <cassert>
#include <cstdlib>//for NULL
#include <iostream>
#include <vector>
using namespace std;

HeapPriorityQueue::HeapPriorityQueue() {
  // Empty... nothing needs to be done.
}

HeapPriorityQueue::~HeapPriorityQueue() {
  // no clean-up to do, since the heap is not dynamically allocated
}

void HeapPriorityQueue::add(MazeState *elem) {
  list.push_back(elem);
  int size = (int)list.size();
  swap_up(size - 1);
}

MazeState * HeapPriorityQueue::remove() {
  assert(!is_empty());
  MazeState *ret = list[0];
  int size = (int)list.size();
  list[0] = list[size - 1];
  list.resize(list.size() - 1);
  swap_down(0);
  return ret;
}


bool HeapPriorityQueue::is_empty() {
  return (list.size() == 0);
}

// You might find these helper functions helpful...
int HeapPriorityQueue::parent(int index) {
  return (index - 1) / 2;
}

int HeapPriorityQueue::first_child(int index) {
  return 2 * index + 1;
}

bool HeapPriorityQueue::is_root(int index) {
  return index == 0;
}

bool HeapPriorityQueue::is_leaf(int index) {
  return num_children(index) == 0;
}

int HeapPriorityQueue::num_children(int index) {
  int fchild = first_child(index);
  return max(0, min(2, (int)heap.size() - fchild));
}

void HeapPriorityQueue::swap_up(int index) {
  if (index == 0) {
    return;
  }
  int p = parent(index);
  if (list[index]->getBadness() < list[p]->getBadness()) {
    MazeState *temp = list[index];
    list[index] = list[p];
    list[p] = temp;
    swap_up(p);
  }
}


void HeapPriorityQueue::swap_down(int i) {
  int small = i;
  int left = first_child(i);
  int right = left +1;
  int n = (int)list.size();
  if (left < n && list[left]->getBadness() < list[small]->getBadness()) {
    small = left;
  }
  if (right < n && list[right]->getBadness() < list[small]->getBadness()) {
    small = right;
  }
  if (small != i) {
    MazeState *temp = list[i];
    list[i] = list[small];
    list[small] = temp;
    swap_down(small);
  }
}


#endif
