#include "graph.h"
#include <fstream>
#include <stdexcept>

Graph::Graph(std::size_t n, std::string filename): n(n), matrix(n, std::vector<size_t>(n, 0)){
  std::ifstream ifs(filename);
  std::size_t i = 0;
  std::size_t x;
  while (ifs >> x) {
    matrix[i/n][i%n] = x;
    ++i;
  }

  if (i<n*n)
    throw std::length_error("Graph matrix is too small!");
}

Graph::Graph(std::size_t n,
             std::string graph, 
             std::string coordinate_file): Graph(n, graph) {
  coordinates.resize(n);
  std::ifstream ifs (coordinate_file);
  size_t x, y, i=0;
  while (ifs >> x >> y)
    coordinates[i++] = {x, y};
  if (i<n)
    throw std::length_error("Not enough point coordinates!");
}


const std::vector<std::size_t>& Graph::operator[](std::size_t i) const {
  return matrix[i];
}

// Graph::Graph(std::vector<std::vector<std::size_t>> v): matrix(v), n(v.size()) {}

std::size_t Graph::size() {
  return n;
}

