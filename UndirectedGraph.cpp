// -----------------------------------------------------------------------
/**
File: UndirectedGraph.cpp

Author: Paresh B.

Web: pareshbhambhani.github.io

Description: Implementation file for UndirectedGraph Header file

**/

#include "UndirectedGraph.hpp"

UndirectedGraph::UndirectedGraph(int numNodes, double density, pair<double, double> distRange)
{
	this-> numNodes = numNodes; //initialize number of nodes
	this-> numEdges = 0;  //initialize number of edges
	
	for (int i = 0; i < numNodes; i++) 
	{
		nodeList.push_back(unordered_map<int, double>()); // initialize the adjacency list
		nodeValues.push_back(numeric_limits<double>::max()); // initialize the node values	
	}

	unsigned seed = chrono::system_clock::now().time_since_epoch().count();
	default_random_engine generator(seed); //seed the random generator engine
	
	// initialize uniform distributions for the graph density and edge distance calculations
	uniform_real_distribution<double> densityDistribution(0.0, 1.0);
	uniform_real_distribution<double> edgeDistDistribution(distRange.first, distRange.second);
	
	//iterate all pairs of nodes
	for (int i=0; i< numNodes -1; i++){
		for (int j = i+1; j < numNodes; j++){
			if(densityDistribution(generator) < density){
				addEdge(i, j, edgeDistDistribution(generator));
			}
		}
	}
}

void UndirectedGraph::getNeighbors(int node, vector<int> &neighbors)
{
  neighbors.clear();
  for (auto it = nodeList.at(node).begin(); it != nodeList.at(node).end(); ++it) // iterate the map
    neighbors.push_back(it->first); // store the keys (the connected nodes)
}