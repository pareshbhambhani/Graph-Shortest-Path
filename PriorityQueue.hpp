// -----------------------------------------------------------------------
/**
File: PriorityQueue.hpp

Author: Paresh B.

Web: pareshbhambhani.github.io

Description: Priority Queueing Header file for Monte Carlo Simulation for shortest path calculaiton

**/ 


#ifndef _PRIORITY_QUEUE_H_
#define _PRIORITY_QUEUE_H_

#include <vector>
#include <algorithm>
#include <utility>

using namespace std;

template <class T1, class T2>

class PriorityQueue
{

public:
  // Constructor; creates a priority queue with elements type T1 and values type T2.
  // @param preferHighValues True if you want high values to have higher priority, otherwise low values will have higher priority.
  PriorityQueue(bool preferHighValues = true);

  // Sets the comparator function such that the ordering is ascending or descending.
  void setComparator(bool preferHighValues);

  // Access the top element in this priority queue.
  // @return Returns the element with the highest priority without removing it from the queue.
  T1 top();

  // Remove the top element from the queue.
  // @return Removes and returns the element with the highest priority from the queue.
  T1 pop();

  // Insert an element into this priority queue.
  // @param element The element to insert into the queue.
  // @param value The value of the element (determines its priority).
  void push(T1 element, T2 value);

// Gets the size of this priority queue.
  // @return The number of elements in the queue.
  int size();

  // Tests if the priority queue is empty.
  // @return True if the priority queue is empty, otherwise false.
  bool empty();

  // Clears the contents of the priority queue.
  void clear();

  // Checks for the first occurrence of a specific element in the the queue.
  // @param element The element whose existence in the queue is to be determined.
  // @return True if the element exists, false otherwise.
  bool contains(T1 element);

  // Changes the value of the first occurrence of a specific element.
  // @param element The element whose value we wish to change.
  // @param value The new value of the element.
  void changePriority(T1 element, T2 value);

private:

  // The vector of elements in this queue; the first item in the pair is
  // the actual element of type T, while the second item is the priority.
  vector <pair<T1,T2>> elements;

  // Comparison function where the smaller values have higher priority.
  static bool CompareAscending(const pair<T1, T2> &lhs, const pair<T1, T2> &rhs);

  // Comparison function where larger values have higher priority.
  static bool CompareDescending(const pair<T1, T2> &lhs, const pair<T1, T2> &rhs);

  // Function object that is used to find the first matching element (compares the first item of the pair).
  class FindFirst
  {
  public:
    explicit FindFirst(T1 item) : item(item) {}
    inline bool operator()(const pair<T1, T2> &elem) { return item == elem.first; }
  private:
    T1 item;
  };

};
#endif // _PRIORITY_QUEUE_H_
