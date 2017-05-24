// -----------------------------------------------------------------------
/**
File: ShortestPath.cpp

Author: Paresh B.

Web: pareshbhambhani.github.io

Description: Implementation file for ShortestPath Header file

**/ 

#include "ShortestPath.hpp"

ShortestPath::ShortestPath(UndirectedGraph &graph, int startNode, int endNode)
{
  // we want the priority queue to always behave such that low values have higher priority
  pQueue.setComparator(false);

  updateGraph(graph, startNode, endNode);
}

void ShortestPath::updateGraph(UndirectedGraph &graph, int startNode, int endNode)
{
  initialize(graph);

  currStartNode = startNode;
  currEndNode = endNode;
  pathExists = run(startNode, endNode);
}

list<int> ShortestPath::path()
{
  if (!exists()) // there is no path from the starting to the ending node
    return list<int>();
  else if (currStartNode == currEndNode) // the starting and ending nodes are the same
    return list<int>(2, currStartNode);

  list<int> path;
  int currNode = currEndNode;

  // reconstruct the shortest path from the ending node to the starting node
  path.push_front(currNode);
  while (previous[currNode] != -1) {
    path.push_front(previous[currNode]);
    currNode = previous[currNode]; // traverse backwards to the starting node
  }

  return path;
}

void ShortestPath::initialize(UndirectedGraph &graph)
{
  currGraph = &graph;

  pQueue.clear();
  visited.clear();
  previous.clear();

  for (int i = 0; i < currGraph->getNumNodes(); i++) {
    currGraph->setNodeValue(i, numeric_limits<double>::max()); // re-initialize the node values
    visited.push_back(false); // mark all nodes as un-visited
    previous.push_back(-1); // mark all previous nodes as undefined
  }
}

bool ShortestPath::run(int startNode, int endNode)
{
  currGraph->setNodeValue(startNode, 0.0); // initialize distance from the starting node to itself
  pQueue.push(startNode, 0.0); // start with the starting node in the priority queue

  // temporary variables
  int currNode; // holds the current node being examined
  double distFromStart = 0.0; // accumulates the shortest distance from the starting node
  vector<int> neighbors; // holds the adjacent nodes to the current node

  while (!pQueue.empty()) { // main algorithm loop
    currNode = pQueue.pop(); // get the node with the smallest distance
    visited[currNode] = true; // mark this node as visited
    if (currNode == endNode) return true; // we are at the target node; terminate

    // acquire and iterate the neighboring nodes
    currGraph->getNeighbors(currNode, neighbors);
    for (vector<int>::iterator it = neighbors.begin(); it != neighbors.end(); ++it) {
      // compute the shortest distance from the starting node
      distFromStart = currGraph->getNodeValue(currNode) + currGraph->getEdgeValue(currNode, *it);

      // keep the shortest distance if it is less than the current value at the neighboring node AND
      // if the neighboring node has not yet been visited
      if ((distFromStart < currGraph->getNodeValue(*it)) && !visited[*it]) {
        currGraph->setNodeValue(*it, distFromStart); // update the new value
        previous[*it] = currNode; // keep track of the parent node

        if (pQueue.contains(*it)) // update the node's value if it already exists in the queue
          pQueue.changePriority(*it, distFromStart);
        else // otherwise add it to the queue to be processed
          pQueue.push(*it, distFromStart);
      }
    }
  }

  return false; // the starting and ending nodes are in disconnected graphs
}
