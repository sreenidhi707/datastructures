#include "graph.h"

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

int Graph::V()
{
  return numVertices;
}

int Graph::E()
{
  return numEdges;
}

void Graph::V(int v)
{
  numVertices = v;

  //Create the adjacency list
  for (size_t i = 0; i < v; i++)
  {
	  adj.push_back(new Node(i));
  }
}

void Graph::E(int e)
{
  numEdges = e;
}

void Graph::addEdge(int src, int dst)
{
	//For undirected graph, every edge is represented twice in the adjacency list
	addEdgePrivate(src, dst);
	addEdgePrivate(dst, src);
}
