#include "graph.h"


std::pair<size_t, std::vector<size_t>> astar(Graph g, size_t start, size_t end) {
  if (g.size()==0 || start>=g.size() || end>=g.size()) {
    throw std::invalid_argument("received weird args");
  }
  // minimal path to a node + heuristic and node's id;
  std::set<Pair> s;   // old: std::priority_queue<Pair, std::vector<Pair>, std::greater<Pair>> q;
  // node -> min path length on it, previous node on this path
  std::vector<Pair> info(g.size());
  // visited node ids;
  std::unordered_set<size_t> deleted;
  for (size_t i=0; i!=g.size(); ++i) {
    s.insert({i==start ? g.coords(start).norm1(g.coords(end)) : Graph::Inf(), i});
    info[i] = {i==start ? 0 : Graph::Inf(), g.size()};
  }

  size_t cur_id, cur_sum, cur_len;
  do {
    cur_sum = s.begin()->first;
    cur_id = s.begin()->second;
    cur_len = cur_sum - g.coords(cur_id).norm1(g.coords(end));
    s.erase(s.begin());
    deleted.insert(cur_id);
    for (size_t i=0; i<g.size(); ++i) {
      if (g[cur_id][i]!=Graph::Inf() &&
          deleted.find(i)==deleted.end() &&
          info[i].first > g[cur_id][i] + cur_len) {

            auto to_erase = s.find({info[i].first, i});
            s.erase(to_erase);
            info[i].first = g[cur_id][i] + cur_len;
            info[i].second = cur_id;
            s.insert({info[i].first + g.coords(i).norm1(g.coords(end)), i});
      }
    }
  }
  while (cur_id!=end && !s.empty() && s.begin()->first!=Graph::Inf());
  
  size_t res1 = info[end].first;
  std::vector<size_t> tmp;
  for (size_t cur = end; cur!=start; cur = info[cur].second)
    tmp.push_back(cur);
  tmp.push_back(start);
  std::vector<size_t> res2 (tmp.rbegin(), tmp.rend());
  return {res1, res2};
}
