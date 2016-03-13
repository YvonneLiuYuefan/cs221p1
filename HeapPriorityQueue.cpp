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
  heap.push_back(elem);
  int size = (int)heap.size();
  swap_up(size - 1);
}

MazeState * HeapPriorityQueue::remove() {
  assert(!is_empty());
  MazeState *ret = heap[0];
  int size = (int)heap.size();
  heap[0] = heap[size - 1];
  heap.resize(heap.size() - 1);
  swap_down(0);
  return ret;
}


bool HeapPriorityQueue::is_empty() {
  return (heap.size() == 0);
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
  if (heap[index]->getBadness() < heap[p]->getBadness()) {
    MazeState *temp = heap[index];
    heap[index] = heap[p];
    heap[p] = temp;
    swap_up(p);
  }
}


void HeapPriorityQueue::swap_down(int i) {
  int small = i;
  int left = first_child(i);
  int right = left +1;
  int n = (int)heap.size();
  if (left < n && heap[left]->getBadness() < heap[small]->getBadness()) {
    small = left;
  }
  if (right < n && heap[right]->getBadness() < heap[small]->getBadness()) {
    small = right;
  }
  if (small != i) {
    MazeState *temp = heap[i];
    heap[i] = heap[small];
    heap[small] = temp;
    swap_down(small);
  }
}


#endif
