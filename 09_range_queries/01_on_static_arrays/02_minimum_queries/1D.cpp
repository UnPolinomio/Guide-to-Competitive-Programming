#include <bits/stdc++.h>
#define fore(x, a, b) for (lli x = a, ___limit___ = b; x < ___limit___; ++x)
#define all(x) x.begin(), x.end()
#define deb(x) cout << #x << ": " << (x) << '\n';
using namespace std;
using lli = long long int;
using ii = pair<lli, lli>;
using vi = vector<lli>;
using vb = vector<bool>;

lli largest_power(lli x) {
  // if x = 0b10010 returns 10000
  // caveat: will fail if x>=2^32

  assert(x >= 1);

  lli ans{32};
  while (--ans >= 0)
    if (x & (1ll << ans)) break;

  return ans;
}

struct MinimumQuery {
  vector<vi> mins{};  // mins[exp][s] = min value in [s, s+2^exp)
  lli n{};

  MinimumQuery(const vi& v) {
    n = v.size();
    lli max_exp{largest_power(n)};
    mins.resize(max_exp + 1);
    mins[0] = v;

    fore(exp, 1, max_exp + 1) {
      mins[exp].resize(n - (1ll << exp) + 1);
      fore(start, 0, mins[exp].size()) {
        lli a{mins[exp - 1][start]};
        lli b{mins[exp - 1][start + (1 << (exp - 1))]};
        mins[exp][start] = min(a, b);
      }
    }
  }

  lli query(lli a, lli b) {
    assert(a >= 0 && b >= 0 && a <= n && b <= n);
    lli exp{largest_power(b - a)};

    return min(mins[exp][a], mins[exp][b - (1 << exp)]);
  }
};

int main() {
  vi v{2, 5, 3, 6, 1, 4, 7};
  MinimumQuery mq(v);

  for (auto& row : mq.mins) {
    for (lli el : row) cout << el << ' ';
    cout << '\n';
  }

  cout << mq.query(3, 6) << '\n';
  cout << mq.query(1, 4) << '\n';

  return 0;
}
