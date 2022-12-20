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
  vector<vi> adj{};
  lli n{};

  Graph(lli n) : n(n) { adj.resize(n); }

  void add_edge(lli u, lli v) {
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
};

void to_bottom(Graph& g, vector<ii>& max_depth, lli n, lli p) {
  max_depth[n] = {0, 0};
  for (lli v : g.adj[n]) {
    if (v == p) continue;
    to_bottom(g, max_depth, v, n);
    lli d = max_depth[v].first + 1;
    if (d > max_depth[n].first)
      max_depth[n] = {d, max_depth[n].first};
    else if (d > max_depth[n].second)
      max_depth[n].second = d;
  }
}

void to_top(Graph& g, vector<ii>& max_depth, lli n, lli p) {
  if (p != -1) {
    lli d{max_depth[n].first + 1};
    lli d2{d == max_depth[p].first ? max_depth[p].second : max_depth[p].first};
    d2 += 1;

    if (d2 > max_depth[n].first) {
      max_depth[n] = {d2, max_depth[n].first};
    } else if (d2 > max_depth[n].second) {
      max_depth[n].second = d2;
    }
  }

  for (lli v : g.adj[n]) {
    if (v == p) continue;
    to_top(g, max_depth, v, n);
  }
}

vi all_longest_paths(Graph& g) {
  vector<ii> max_depth(g.n, {0, 0});
  to_bottom(g, max_depth, 0, -1);
  to_top(g, max_depth, 0, -1);
  vi ans(g.n);
  fore(i, 0, g.n) ans[i] = max_depth[i].first;
  return ans;
}

int main() {
  Graph g(6);
  g.add_edge(1, 5);
  g.add_edge(0, 2);
  g.add_edge(0, 1);
  g.add_edge(1, 4);
  g.add_edge(0, 3);
  for (lli el : all_longest_paths(g)) cout << el << ' ';
  cout << '\n';
  return 0;
}
