#include <iostream>
#include <fstream>

#include "graph.h"

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
  while (e--)
  {
    file >> srcV;
    file >> dstV;
    g.addEdge(srcV, dstV);
  }
}