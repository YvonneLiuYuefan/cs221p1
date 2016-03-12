cmake_minimum_required(VERSION 3.3)
project(p1)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES
    ArrayQueue.cpp
    ArrayQueue.hpp
    ArrayStack.cpp
    ArrayStack.hpp
    BagOfMazeStates.hpp
    HeapPriorityQueue.cpp
    HeapPriorityQueue.hpp
    LinkedListDict.cpp
    LinkedListDict.hpp
    LinkedListQueue.cpp
    LinkedListQueue.hpp
    LinkedListStack.cpp
    LinkedListStack.hpp
    MazeState.hpp
    PredDict.hpp
    SliderPuzzle.cpp
    SliderPuzzle.hpp
    solve.cpp
    Sudoku.cpp
    Sudoku.hpp
    TextMaze.cpp
    TextMaze.hpp
    UnsortedPriorityQueue.cpp
    UnsortedPriorityQueue.hpp)

add_executable(p1 ${SOURCE_FILES})