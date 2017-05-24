// -----------------------------------------------------------------------
/**
File: UndirectedGraph.hpp

Author: Paresh B.

Web: pareshbhambhani.github.io

Description: Graph Header file for Monte Carlo Simulation for shortest path calculaiton.

**/ 

#ifndef _UNDIRECTED_GRAPH_H_
#define _UNDIRECTED_GRAPH_H_

#include <iostream>
#include <vector>
#include <utility>
#include <unordered_map>
#include <limits>
#include <chrono>
#include <random>

using namespace std;

class UndirectedGraph
{
public:
  // Constructor.
  // @param numNodes The number of nodes in this graph.
  // @param density The edge density of this graph, from 0.0 to 1.0.
  // @param distRange The edge distance range (min and max values).
  UndirectedGraph(int numNodes, double density, pair<double, double> distRange);

  // Returns the number of nodes in this graph.
  // @return The number of nodes in this graph.
  int getNumNodes();

  // Returns the number of edges in this graph.
  // @return The number of edges in this graph.
  int getNumEdges();

  // Test if there is an edge between two nodes.
  // @param node1 The first node.
  // @param node2 The second node.
  // @return True if an edge exists, otherwise false.
  bool isAdjacent(int node1, int node2);

  // Get all nodes connected to the given node.
  // @param node The node to check for any connections.
  // @param neighbors The reference vector of neighbors returned; any existing content will be cleared.
  void getNeighbors(int node, vector<int> &neighbors);

  // Adds an edge between the two nodes.
  // @param node1 The first node.
  // @param node2 The second node.
  // @param dist The edge distance (optional).
  void addEdge(int node1, int node2, double dist = 0.0);

  // Delete the edge between the two nodes.
  // @param node1 The first node.
  // @param node2 The second node.
  void deleteEdge(int node1, int node2);

  // Returns the value associated with the node.
  // @param node The node whose value we want.
  // @return The value at that node.
  double getNodeValue(int node);

  // Sets the value associated with the node.
  // @param node The node whose value we want to set.
  // @param value The value to set.
  void setNodeValue(int node, double value);

  // Returns the value associated with the edge between the two nodes.
  // @param node1 The first node.
  // @param node2 The second node.
  // @return The edge value.
  double getEdgeValue(int node1, int node2);

  // Sets the edge value between the two nodes.
  // @param node1 The first node.
  // @param node2 The second node.
  // @param dist The edge value to set.
  void setEdgeValue(int node1, int node2, double value);

private:
  // The number of nodes in this undirected graph.
  int numNodes;

  // The number of edges in this undirected graph.
  int numEdges;

 // The adjacency list representing this undirected graph.
  // Each vector element is a key-value pair, where the key represents the
  // connected node, and the the value represents the edge distance.
  vector<unordered_map<int, double>> nodeList;

  // The value of each node in this undirected graph.
  vector<double> nodeValues;

};

// Inline function definitions placed here to avoid linker errors.

inline int UndirectedGraph::getNumNodes()
{
  return numNodes;
}

inline int UndirectedGraph::getNumEdges()
{
  return numEdges;
}

inline bool UndirectedGraph::isAdjacent(int node1, int node2)
{
  // go to the index specified by node1 and search for the key specified by node2
  return nodeList.at(node1).count(node2) > 0;
}

inline void UndirectedGraph::addEdge(int node1, int node2, double dist /*=0.0*/)
{
  setEdgeValue(node1, node2, dist);
}

inline void UndirectedGraph::deleteEdge(int node1, int node2)
{
  nodeList.at(node1).erase(node2);
  nodeList.at(node2).erase(node1);

  numEdges--; // update the number of edges
}

inline double UndirectedGraph::getNodeValue(int node)
{
  return nodeValues.at(node);
}

inline void UndirectedGraph::setNodeValue(int node, double value)
{
  nodeValues.at(node) = value;
}

inline double UndirectedGraph::getEdgeValue(int node1, int node2)
{
  return nodeList.at(node1).at(node2);
}

inline void UndirectedGraph::setEdgeValue(int node1, int node2, double value)
{
  // increment the number of edges if the nodes are not already connected
  if (!isAdjacent(node1, node2))
    numEdges++;

  nodeList.at(node1)[node2] = value;
  nodeList.at(node2)[node1] = value;
}

#endif // _UNDIRECTED_GRAPH_H_

