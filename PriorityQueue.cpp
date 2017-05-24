// -----------------------------------------------------------------------
/**
File: PriorityQueue.cpp

Author: Paresh B.

Web: pareshbhambhani.github.io

Description: Implementation file for PriorityQueue Header file

**/ 

#include "PriorityQueue.hpp"

using namespace std;

template<class T1, class T2>
PriorityQueue<T1, T2>::PriorityQueue(bool preferHighValues)
{
  setComparator(preferHighValues);
}

template<class T1, class T2>
void PriorityQueue<T1, T2>::setComparator(bool preferHighValues)
{
  comparison = preferHighValues ? CompareDescending : CompareAscending;
}

template<class T1, class T2>
inline PriorityQueue<T1, T2>::top()
{
  return elements.front().first; // return the element at the top of the heap
}

template <class T1, class T2>
T1 PriorityQueue<T1, T2>::pop()
{
  pop_heap(elements.begin(), elements.end(), comparison); // pop the top element from the heap range

  // save and delete the element
  T1 topElement = elements.back().first;
  elements.pop_back();

  return topElement;
}

template <class T1, class T2>
void PriorityQueue<T1, T2>::push(T1 element, T2 value)
{
  // insert the element and place it in the correct position in the heap
  elements.push_back(pair<T1, T2>(element, value));
  push_heap(elements.begin(), elements.end(), comparison);
}

template <class T1, class T2>
inline int PriorityQueue<T1, T2>::size()
{
  return elements.size();
}

template <class T1, class T2>
inline bool PriorityQueue<T1, T2>::empty()
{
  return elements.empty();
}

template <class T1, class T2>
inline void PriorityQueue<T1, T2>::clear()
{
  elements.clear();
}

template <class T1, class T2>
inline bool PriorityQueue<T1, T2>::contains(T1 element)
{
  return find_if(elements.begin(), elements.end(), FindFirst(element)) != elements.end();
}

template <class T1, class T2>
void PriorityQueue<T1, T2>::changePriority(T1 element, T2 value)
{
  class vector<std::pair<T1, T2> >::iterator it = find_if(elements.begin(), elements.end(), FindFirst(element));
  if (it != elements.end()) {
    (*it).second = value;
    make_heap(elements.begin(), elements.end(), comparison);
  }
}

template <class T1, class T2>
bool PriorityQueue<T1, T2>::CompareAscending(const pair<T1, T2> &lhs, const pair<T1, T2> &rhs)
{
  return lhs.second > rhs.second;
}

template <class T1, class T2>
bool PriorityQueue<T1, T2>::CompareDescending(const pair<T1, T2> &lhs, const pair<T1, T2> &rhs)
{
  return lhs.second < rhs.second;
}
