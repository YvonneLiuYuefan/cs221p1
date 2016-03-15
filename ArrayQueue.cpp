#ifndef _ARRAYQUEUESOLN_CPP
#define _ARRAYQUEUESOLN_CPP

//ArrayQueueSoln.cpp

#include "ArrayQueue.hpp"
#include <cstdlib> //for NULL
#include <cassert>
#include <iostream>
using namespace std;

// 221 STUDENTS:
//
// This skeleton file (along with the .hpp) is
// here to help get you started, but you are
// free to change function signatures, etc.
// as long as ArrayQueue is some subtype
// of BagOfMazeStates
ArrayQueue::ArrayQueue()
{
  // Constructor: initialize member variables
  //              and do any other initialization
  //              needed (if any)
  // implement constructor
    head = 0;
    tail = 0;
    capacity = INIT_SIZE - 1;
    array = new MazeState*[INIT_SIZE];
    num_elements = 0;
} 

void ArrayQueue::add(MazeState *elem) {
  if ((tail+1) % (capacity+1) == head) {
    // queue is full
    ensure_capacity(capacity+1); // ensure_capacity makes grows the array.
  }
  // Your code goes here...                     ****DONE****
    array[tail] = elem;
    tail = (tail + 1) % (capacity+1);
    num_elements++;
}

MazeState *ArrayQueue::remove() {
  // implement remove method              ****DONE****
    assert(!is_empty());
    MazeState *temp = array[head];
    head = (head+1) % (capacity+1);
    
    return temp;

}

bool ArrayQueue::is_empty()
{
  return (head==tail);
}

// implement ensure_capacity (but leave this to last.. just start with lots of capacity!)

void ArrayQueue::ensure_capacity(int n)
{
  if (capacity < n) {
    // Make plenty of room.
    int target_capacity = (n > 2*capacity+1) ? n : (2*capacity+1);

    // Set the current array aside and make room for the new one.
    MazeState **old_array = array;
    array = new MazeState*[target_capacity];

    // Copy each element of the old array over.
    for (int i = 0; i < (n - 1); i++) {
      array[i] = old_array[(head + i)%capacity];
    }
    // Fix front and back and capacity so they correspond to the new array.
    head = 0;
    tail = capacity;
    capacity = target_capacity - 1;

    // Delete the old array.              ****DONE****
    delete[] old_array;
  }

}


ArrayQueue::~ArrayQueue() {
  delete array;
}

#endif
