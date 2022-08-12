#include <bits/stdc++.h>
#define fore(x, a, b) for (lli x = a, ___limit___ = b; x < ___limit___; ++x)
#define all(x) x.begin(), x.end()
#define deb(x) cout << #x << ": " << (x) << '\n';
using namespace std;
using lli = long long int;
using ii = pair<lli, lli>;
using vi = vector<lli>;
using vb = vector<bool>;

struct WeightedGraph {
  lli n{};
  vector<vi> matrix{};

  WeightedGraph(lli _n, lli default_value = -1) {
    n = _n;
    matrix.resize(n, vi(n, default_value));
    fore(i, 0, n) matrix[i][i] = 0;
  }

  void add_edge(lli a, lli b, lli w, bool undirected = true) {
    assert(a < n && a >= 0 && b < n && b >= 0);
    assert(a != b || w == 0);
    matrix[a][b] = w;
    if (undirected) matrix[b][a] = w;
  }
};

vector<vi> floyd_warshall(const WeightedGraph& graph) {
  vector<vi> dist(graph.matrix);

  fore(intermediate, 0, graph.n) {
    fore(from, 0, graph.n) {
      fore(to, 0, graph.n) {
        lli a{dist[from][intermediate]}, b{dist[intermediate][to]};
        if (a == -1 || b == -1) continue;
        if (dist[from][to] != -1 && a + b >= dist[from][to]) continue;
        dist[from][to] = a + b;
      }
    }
  }

  return dist;
}

int main() {
  WeightedGraph graph(5);
  graph.add_edge(1, 0, 5);
  graph.add_edge(2, 1, 2);
  graph.add_edge(3, 0, 9);
  graph.add_edge(3, 2, 7);
  graph.add_edge(4, 0, 1);
  graph.add_edge(4, 3, 2);

  auto res{floyd_warshall(graph)};
  for (auto& row : res) {
    for (lli el : row) cout << el << ' ';
    cout << '\n';
  }

  return 0;
}
