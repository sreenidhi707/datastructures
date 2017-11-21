#include <iostream>
#include <stack>
#include <queue>
#include "graph.h"

int Graph::V()
{
  return v;
}

void Graph::V(int _v)
{
  v = _v;

  //Create the adjacency list
  for (size_t i = 0; i < v; i++)
  {
    adj.push_back(new Node(i));
  }
}

int Graph::E()
{
  return e;
}

void Graph::addEdgePrivate(int src, int dst)
{
  //Get the node corresponding to the source
  Node* node = adj[src];
  
  //Run till the last node
  while (node->next != NULL)
  {
    node = node->next;
  }
  
  //Now, node is pointing to the last node in the list
  Node* d = new Node(dst);
  node->next = d;
}

void Graph::addEdge(int src, int dst)
{
  //For undirected graph, every edge is represented twice in the adjacency list
  addEdgePrivate(src, dst);
  addEdgePrivate(dst, src);

  e++; //Increment edge count only once
  std::cout << "Graph::addEdge():: Added edge " << src << " <--> " << dst << std::endl;
}

void printVisitedNodes(Graph* g) 
{
  for (auto node : g->adj)
  {
    std::cout << "Node:" << node->val << ":" << std::endl;
    while (node != NULL)
    {
      if (node->visited)
      {
        std::cout << node->val << "--";
      }
      node = node->next;
    }
    std::cout << std::endl;
  }
}

void printGraph(Graph* g)
{
  std::cout << "Printing graph" << std::endl;
  std::cout << "V:" << g->V() << std::endl;
  std::cout << "E:" << g->E() << std::endl;

  for (auto& node : g->adj)
  {
    Node* n = node;
    while (n)
    {
      std::cout << n->val << "-->";
      n = n->next;
    }
    std::cout << "NULL" << std::endl;
  }
}

void dfsIterative(Graph* g, Node* _node)
{
  std::stack<Node*> nodes;
  nodes.push(_node);

  while (!nodes.empty())
  {
    Node* node = nodes.top();
    node->visited = true;

    node = node->next;
    nodes.pop();
    while (node != NULL)
    {
      if (!node->visited)
      {
        nodes.push(node);
      }
      node = node->next;
    }
  }
}

void dfsIterativeAll(Graph* g)
{
  for (auto* node : g->adj)
  {
    dfsIterative(g, node);
  }
}

void dfsRecursive(Graph* g, Node* node)
{
  if (!node->visited)
  {
    node->visited = true;
    
    Node* nextNode = g->adj[node->val]->next;
    while (nextNode != NULL)
    {
      dfsRecursive(g, nextNode);
    }
  }
  else
  {
    return;
  }
}

void dfsRecursiveAll(Graph* g)
{
  for (auto* node : g->adj)
  {
    dfsRecursive(g, node);
  }
}

void bfsIterative(Graph* g, Node* node)
{
  std::queue<Node*> nodes;
  nodes.push(node);

  while (!nodes.empty())
  {
    Node* node = nodes.front();
    node->visited = true;

    while (node != NULL)
    {
      if (!node->visited)
      {
        nodes.push(node);
      }
      node = node->next;
    }

    nodes.pop();
  }
}

void bfsIterativeAll(Graph* g)
{
  for (auto* node : g->adj)
  {
    bfsIterative(g, node);
  }
}