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

vi dijkstra(const Graph& graph, lli start) {
  vi dist(graph.n, -1);
  priority_queue<ii> to_visit{};  // ( -distance, node )
  dist[start] = 0;
  to_visit.emplace(0, start);

  while (!to_visit.empty()) {
    auto [distance, node] = to_visit.top();
    to_visit.pop();
    distance *= -1;

    if (dist[node] != distance) continue;  // already visited
    for (auto [to, weight] : graph.edges[node]) {
      lli new_distance{distance + weight};
      if (dist[to] != -1 && new_distance >= dist[to]) continue;
      dist[to] = new_distance;
      to_visit.emplace(-new_distance, to);
    }
  }

  return dist;
}

int main() {
  Graph graph{6};

  graph.add_edge(1, 2, 5);
  graph.add_edge(1, 4, 9);
  graph.add_edge(1, 5, 1);
  graph.add_edge(2, 3, 2);
  graph.add_edge(3, 4, 6);
  graph.add_edge(4, 5, 2);

  vi result{dijkstra(graph, 1)};
  for (lli i : result) cout << i << ' ';
  cout << '\n';

  return 0;
}
