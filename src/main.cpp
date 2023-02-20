#include <iostream>
#include "graph.h"

int main(int argc, char ** argv) {
  std::string src = "../examples/1.txt";
  std::string coords = "../examples/coordinates_for_12.txt";
  size_t size = 12, start = 0, end = 7;
  if (argc==6) {
    src = std::string(argv[1]);
    coords = std::string(argv[2]);
    size = std::atoi(argv[3]);
    start = std::atoi(argv[4]);
    end = std::atoi(argv[5]);
  }

  Graph g(size, src, coords);
  //auto res = dijkstra(g, 0, 7);
  auto res = astar(g, start, end);
  std::cout << "*** Astart algo ***" << std::endl;
  std::cout << "Path length is " << res.first << '\n';
  std::cout << "Path is:\n";
  for (auto c: res.second)
    std::cout << c << "---->\n";

  res = dijkstra(g, start, end);
  std::cout << "*** Dijkstra algo ***" << std::endl;
  std::cout << "Path length is " << res.first << '\n';
  std::cout << "Path is:\n";
  for (auto c: res.second)
    std::cout << c << "---->\n";

}
