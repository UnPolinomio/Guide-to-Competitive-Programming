#include <bits/stdc++.h>
#define fore(x, a, b) for (lli x = a, ___limit___ = b; x < ___limit___; ++x)
#define all(x) x.begin(), x.end()
#define deb(x) cout << #x << ": " << (x) << '\n';
using namespace std;
using lli = long long int;
using ii = pair<lli, lli>;
using vi = vector<lli>;
using vb = vector<bool>;

struct Graph {
  lli n{};
  vector<vector<ii>> edges{};  // ( to, weight )

  Graph(lli _n) {
    n = _n;
    edges.resize(n);
  }

  void add_edge(lli a, lli b, lli w, bool undirected = true) {
    assert(a < n && a >= 0 && b < n && b >= 0);
    edges[a].emplace_back(b, w);
    if (undirected) edges[b].emplace_back(a, w);
  }
};

vi spfa(const Graph& graph, lli start) {
  vi distance(graph.n, LLONG_MAX);
  distance[start] = 0;
  queue<lli> nodes{{start}};

  while (!nodes.empty()) {
    lli from{nodes.front()};
    nodes.pop();

    for (const auto& [to, weight] : graph.edges[from]) {
      if (distance[from] + weight < distance[to]) {
        distance[to] = distance[from] + weight;
        nodes.push(to);
      }
    }
  }

  return distance;
}

int main() {
  Graph graph{6};

  graph.add_edge(0, 1, 0);
  graph.add_edge(1, 3, 1);
  graph.add_edge(3, 4, 3);
  graph.add_edge(1, 4, 7);
  graph.add_edge(1, 2, 2);
  graph.add_edge(2, 4, 3);
  graph.add_edge(4, 5, 2);
  graph.add_edge(2, 5, 5);

  vi result{spfa(graph, 0)};
  for (lli i : result) cout << i << ' ';
  cout << '\n';

  return 0;
}
