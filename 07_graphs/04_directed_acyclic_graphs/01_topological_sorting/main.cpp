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
  vector<vi> edges{};

  Graph(lli _n) {
    n = _n;
    edges.resize(n);
  }

  void add_edge(lli a, lli b, bool undirected = true) {
    assert(a < n && a >= 0 && b < n && b >= 0);
    edges[a].push_back(b);
    if (undirected) edges[b].push_back(a);
  }
};

bool _dfs(const Graph& graph, lli node, vb& visited, vb& in_path, vi& res) {
  if (visited[node]) return true;
  if (in_path[node]) return false;

  in_path[node] = true;
  for (lli to : graph.edges[node]) {
    if (!_dfs(graph, to, visited, in_path, res)) return false;
  }
  res.push_back(node);
  visited[node] = true;
  return true;
}

vi topological_sort(const Graph& graph) {
  vb visited(graph.n, false);
  vb in_path(graph.n, false);
  vi ans{};

  fore(i, 0, graph.n) {
    if (visited[i]) continue;
    if (!_dfs(graph, i, visited, in_path, ans)) return {-1};
  }

  reverse(all(ans));
  return ans;
}

int main() {
  Graph graph(7);
  graph.add_edge(1, 2, false);
  graph.add_edge(2, 3, false);
  graph.add_edge(3, 6, false);
  graph.add_edge(4, 1, false);
  graph.add_edge(4, 5, false);
  graph.add_edge(5, 2, false);
  graph.add_edge(5, 3, false);

  vi res{topological_sort(graph)};
  for (lli el : res) cout << el << ' ';
  cout << '\n';

  graph.add_edge(3, 5, false);
  res = topological_sort(graph);
  for (lli el : res) cout << el << ' ';
  cout << '\n';

  return 0;
}
