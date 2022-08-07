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
  vector<tuple<lli, lli, lli>> edges{};  // ( from, to, weight )

  void add_edge(lli a, lli b, lli w, bool undirected = true) {
    assert(a < n && a >= 0 && b < n && b >= 0);
    edges.emplace_back(a, b, w);
    if (undirected) edges.emplace_back(b, a, w);
  }
};

vi bellman_ford(const Graph& graph, lli start) {
  vi distance(graph.n, LLONG_MAX);
  distance[start] = 0;

  fore(i, 1, graph.n) {
    bool changed{false};
    for (const auto& [from, to, weight] : graph.edges) {
      lli dis_from{distance[from]};
      if (dis_from != LLONG_MAX && dis_from + weight < distance[to]) {
        distance[to] = dis_from + weight;
        changed = true;
      }
    }
    if (!changed) break;
  }
  // You can detect a negative cycle if the next (nth) run changes some distance

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

  vi result{bellman_ford(graph, 0)};
  for (lli i : result) cout << i << ' ';
  cout << '\n';

  return 0;
}
