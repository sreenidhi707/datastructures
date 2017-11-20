#pragma once
#include <vector>

class Node
{
 public:
  Node(): val(-1), next(nullptr)
  {
    visited = false;
  }
  Node(int v): val(v), next(nullptr)
  {
    visited = false;
  }
  Node(int v, Node* n): val(v), next(n)
  {
    visited = false;
  }

  //Auxillary data
  int val;
  bool visited;

  Node* next;
};
  
class Graph
{
public:
  Graph() : v(0), 
    e(0) {}

  std::vector<Node*> adj;
  
  int V();
  void V(int v);

  int E();
  void addEdge(int src, int dst);

private:
  int v;
  int e;

  void addEdgePrivate(int src, int dst);
};

//Functions which perform operations on Graph class
void printVisitedNodes(Graph* g);

void dfsIterative(Graph* g, Node* node);
void dfsIterativeAll(Graph* g);
void dfsRecursive(Graph* g, Node* node);
void dfsRecursiveAll(Graph* g);

void bfsIterative(Graph* g, Node* node);
void bfsIterativeAll(Graph* g);
void bfsRecursive(Graph* g, Node* node);
void bfsRecursiveAll(Graph* g);



