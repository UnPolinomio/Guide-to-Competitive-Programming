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

ii _diameter_1(Graph& g, lli n, lli p) {  // ( diameter, max_depth)
  ii ans{0, 0};
  lli mx_depth{0}, mx_depth_2{0};

  for (lli v : g.adj[n]) {
    if (v == p) continue;
    ii d{_diameter_1(g, v, n)};
    ans.first = max(ans.first, d.first);

    if (d.second > mx_depth)
      mx_depth_2 = mx_depth, mx_depth = d.second;
    else if (d.second > mx_depth_2)
      mx_depth_2 = d.second;
  }

  ans.first = max(ans.first, mx_depth + mx_depth_2);
  ans.second = mx_depth + 1;

  return ans;
}

lli diameter_1(Graph& g) { return _diameter_1(g, 0, -1).first; }

ii _diameter_2(Graph& g, lli n, lli p) {  // ( max_length, node )
  ii ans{0, n};

  for (lli v : g.adj[n]) {
    if (v == p) continue;
    ii d{_diameter_2(g, v, n)};
    if (d.first + 1 > ans.first) ans = {d.first + 1, d.second};
  }

  return ans;
}
lli diameter_2(Graph& g) {
  ii d{_diameter_2(g, 0, -1)};
  return _diameter_2(g, d.second, -1).first;
}

int main() {
  Graph tree(7);
  tree.add_edge(4, 1);
  tree.add_edge(5, 1);
  tree.add_edge(0, 1);
  tree.add_edge(0, 2);
  tree.add_edge(0, 3);
  tree.add_edge(3, 6);

  cout << diameter_1(tree) << '\n';
  cout << diameter_2(tree) << '\n';

  return 0;
}
