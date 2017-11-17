#pragma once
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
  
  void addEdgePrivate(int src, int dst);
 public:
  int V();
  int E();
  void V(int v);
  void E(int e);
  void addEdge(int src, int dst);
};



