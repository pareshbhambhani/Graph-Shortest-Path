// -----------------------------------------------------------------------
/**
File: Main.cpp

Author: Paresh B.

Web: pareshbhambhani.github.io

Description: Main file for Monte Carlo Simulation of average shortest path algorithm.

**/
#include "UndirectedGraph.hpp"
#include "ShortestPath.hpp"

using namespace std;

double averageShortestPathLength(int numNodes, double density, pair<double, double> distRange)
{
  UndirectedGraph graph(numNodes, density, distRange);
  ShortestPath p(graph, 0, 0);

  int omit = 1;
  double accumCost = 0.0; // accumulated path cost
  for (int i = 1; i < numNodes; i++) { // compute the n - 1 shortest path lengths
    p.updateGraph(graph, 0, i);
    double cost = p.pathCost();
    if (cost != numeric_limits<double>::max())
      accumCost += cost;
    else
      omit++;
  }

  return accumCost / (numNodes - omit);
}

int main()
{
  int numRuns = 10000;
  double totalCost = 0.0;

  for (int i = 0; i < numRuns; i++)
    totalCost += averageShortestPathLength(50, 0.2, pair<double, double>(1.0, 10.0));
  cout << "density 0.2; average shortest path length: " << totalCost / numRuns << endl;

  totalCost = 0.0;
  for (int i = 0; i < numRuns; i++)
    totalCost += averageShortestPathLength(50, 0.4, pair<double, double>(1.0, 10.0));
  cout << "density 0.4; average shortest path length: " << totalCost / numRuns << endl;

  return 0;
}


 