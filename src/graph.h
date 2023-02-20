#ifndef GRAPH_H
#define GRAPH_H
#include <string>
#include <cstddef>
#include <functional>
#include <queue>
#include <unordered_set>
#include <set>
#include <vector>
#include <limits>
#include <stdexcept>
#include <cmath>
/*
 *  matrix[0]   00 10 -1      (0) -10-> (1) <-13-> (2)
 *  matrix[1]   -1 00 13      
 *  matrix[2]   -1 13 00      
 *  
 *
 */

using std::size_t;
typedef std::pair<size_t, size_t> Pair;
// #define Inf std::numeric_limits<size_t>::max();
struct Point {
  size_t x, y;
  Point(): x(0), y(0) {}
  Point(size_t x, size_t y): x(x), y(y) {}
  Point(const Point& b): x(b.x), y(b.y) {}
  Point& operator=(const Point& b) {
    x = b.x;
    y = b.y;
    return *this;
  }
  size_t norm1(const Point& b) const {
    return (x>b.x ? x-b.x : b.x-x) + (y>b.y ? y-b.y : b.y-y);
  }
  double norm2(const Point& b) const {
    double x1 = static_cast<double>(x), x2 = static_cast<double>(b.x);
    double y1 = static_cast<double>(y), y2 = static_cast<double>(b.y);
    return std::sqrt((x1-x2)*(x1-x2) + (y1-y2)*(y1-y2));
  }
};

class Graph {
 private:
  const std::size_t n;
  std::vector<std::vector<std::size_t>> matrix;
  std::vector<Point> coordinates; 
 public:
  Graph() = delete;
  Graph(std::size_t n, std::string file);
  Graph(std::size_t n, std::string graph, std::string coordinates);
  // Graph(std::vector<std::vector<std::size_t>> v);
  
  const std::vector<std::size_t>& operator[](std::size_t) const;
  std::size_t size();
  static size_t Inf() {
    return std::numeric_limits<size_t>::max();
  }
  const Point& coords(size_t i) {
    return coordinates[i];
  }
};


std::pair<size_t, std::vector<size_t>> dijkstra (Graph g, size_t start, size_t end);
std::pair<size_t, std::vector<size_t>> astar(Graph g, size_t start, size_t end);
#endif // !DEBUG
