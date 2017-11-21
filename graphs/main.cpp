#include <iostream>
#include <fstream>
#include <sstream>

#include "graph.h"

const std::string tinyGPath = "C:\\Users\\sanand2\\Dropbox\\MyProjects\\datastructures\\graphs\\data\\tinyG.txt";
const std::string mediumGPath = "C:\\Users\\sanand2\\Dropbox\\MyProjects\\datastructures\\graphs\\data\\mediumG.txt";

void main()
{
  std::cout << "Starting to run program" << std::endl;

  std::string fileName(mediumGPath);
  std::ifstream file;
  
  
  try
  {
    file.open(fileName);
  }
  catch (std::ios_base::failure& e)
  {
    std::cerr << e.what() << '\n';
  }

  Graph g;

  std::string line;
  int v = -1, e = -1, srcV = -1, dstV = -1;
  
  //std::getline(file, line);

  file >> v;
  file >> e;

  g.V(v);
  while (e--)
  {
    file >> srcV;
    file >> dstV;
    g.addEdge(srcV, dstV);
  }

  printGraph(&g);

}