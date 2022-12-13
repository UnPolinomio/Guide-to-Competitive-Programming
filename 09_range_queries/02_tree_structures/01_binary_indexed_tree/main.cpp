#include <bits/stdc++.h>
#define fore(x, a, b) for (lli x = a, ___limit___ = b; x < ___limit___; ++x)
#define all(x) x.begin(), x.end()
#define deb(x) cout << #x << ": " << (x) << '\n';
using namespace std;
using lli = long long int;
using ii = pair<lli, lli>;
using vi = vector<lli>;
using vb = vector<bool>;

lli p(lli k) { return k & -k; }

struct FenwickTree {
  vi v{};
  vi ft{};

  FenwickTree(initializer_list<lli> l) : v(l) {
    ft = vi(v.size() + 1, 0);
    fore(i, 0, v.size()) add(i, v[i]);
  }

  lli get(lli b) {
    if (b < 0) return 0;
    ++b;

    lli ans{};
    while (b > 0) {
      ans += ft[b];
      b -= p(b);
    }
    return ans;
  }

  lli get(lli a, lli b) { return get(b) - get(a - 1); }

  void add(lli i, lli delta) {
    ++i;
    while (i < (lli)ft.size()) {
      ft[i] += delta;
      i += p(i);
    }
  }

  void update(lli i, lli val) {
    add(i, val - v[i]);
    v[i] = val;
  }
};

int main() {
  FenwickTree ft({1, 2, 3, 4});
  ft.update(2, 10);   // ft = {1, 2, 10, 4}
  ft.update(0, 500);  // ft = {500, 2, 10, 4}
  cout << ft.get(0, 3) << '\n';
  cout << ft.get(1, 2) << '\n';
  cout << ft.get(0, 0) << '\n';
  cout << ft.get(3, 3) << '\n';
  cout << ft.get(2, 2) << '\n';
  return 0;
}
