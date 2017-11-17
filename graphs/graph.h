#pragma once

#include <iostream>
#include <fstream>
#include <vector>

class Node
{
 public:
  Node(): val(-1), next(nullptr){}
  Node(int v): val(v), next(nullptr){}
  Node(int v, Node* n): val(v), next(n){}
  
  int val;
  Node* next;
};
  
class Graph
{
 private:
  int numVertices;
  int numEdges;
  std::vector<Node*> adj;
  
 public:
  int V();
  int E();
  void V(int v);
  void E(int e);
  void addEdge(int src, int dst);
};

void main()
{
	std::cout << "Starting to run program" << std::endl;
	
	std::string fileName("filename.txt");
	std::ifstream file;
	file.open(fileName);

	Graph g;

	int v = -1, e = -1, srcV = -1, dstV = -1;
	file >> v;
	file >> e;

	g.V(v);
	g.E(e);
	while(e--)
	{
		file >> srcV;
		file >> dstV;
		g.addEdge(srcV, dstV);
	}
}

