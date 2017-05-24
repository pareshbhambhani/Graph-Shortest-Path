// -----------------------------------------------------------------------
/**
File: ShortestPath.hpp

Author: Paresh B.

Web: pareshbhambhani.github.io

Description: Shortest Path Header file for Monte Carlo Simulation for shortest path calculaiton. Uses Dijkstra's shortest path algorithm.

**/ 

#ifndef _SHORTEST_PATH_H_
#define _SHORTEST_PATH_H_

#include <iostream>
#include <vector>
#include <list>
#include <limits>

#include "UndirectedGraph.hpp"
#include "PriorityQueue.hpp"

using namespace std;

class ShortestPath
{
public:
  // Constructor. Runs Dijkstra's algorithm.
  // @param graph Reference to the graph object.
  // @param startNode The starting node.
  // @param endNode The ending node.
  ShortestPath(UndirectedGraph &graph, int startNode, int endNode);

  // Updates the reference to the graph object or the starting and ending nodes,
  // and re-runs Dijkstra's algorithm.
  // @param graph Reference to the graph object.
  // @param startNode The starting node.
  // @param endNode The ending node.
  void updateGraph(UndirectedGraph &graph, int startNode, int endNode);

  // Returns whether a path exists between the start and end nodes.
  // @return True if a path exists, otherwise false.
  bool exists();

  // Finds the shortest path in the given graph between the start and end nodes.
  // @return The shortest path from the start to the end nodes (first node at the front, last node at the end).
  list<int> path();

  // Finds the shortest distance in the given graph between the start and end nodes.
  // @return The cost of the shortest path from the start to the end nodes.
  double pathCost();

private:
  // Handles the initializations of the graph object and stl containers
  // before running the algorithm's main loop.
  // @param graph Reference to the graph object.
  void initialize(UndirectedGraph &graph);

  // Handles the execution of the main loop of the algorithm.
  // @param startNode The starting node.
  // @param endNode The ending node.
  // @return True if the shortest path exists, otherwise false.
  bool run(int startNode, int endNode);

  // Pointer to the graph object.
  UndirectedGraph *currGraph;

  // Priority queue used internally for the algorithm.
  PriorityQueue<int, double> pQueue;

  // The current starting node.
  int currStartNode;

  // The current ending node.
  int currEndNode;

  // Flag for the existance of a path from the start to the end nodes.
  bool pathExists;

  // The nodes that have or have not been visited.
  vector<bool> visited;

  // Stores the previous node in the optimal path.
  vector<int> previous;

};

// Inline function definitions placed here to avoid linker errors.

inline bool ShortestPath::exists()
{
  return pathExists;
}

inline double ShortestPath::pathCost()
{
  return currGraph->getNodeValue(currEndNode); // the cost at the target node
}

#endif // _SHORTEST_PATH_H_

