#include <bits/stdc++.h>
#define fore(x, a, b) for (lli x = a, ___limit___ = b; x < ___limit___; ++x)
#define all(x) x.begin(), x.end()
#define deb(x) cout << #x << ": " << (x) << '\n'
using namespace std;
using lli = long long int;
using ii = pair<lli, lli>;
using vi = vector<lli>;
using vb = vector<bool>;

lli max_value(vi weights, vi values, lli limit) {
  vi maxs(limit + 1ll, 0);

  fore(i, 0, weights.size()) {
    for (lli j = limit - weights[i]; j >= 0; --j) {
      maxs[j + weights[i]] = max(maxs[j] + values[i], maxs[j + weights[i]]);
    }
  }

  return maxs[limit];
}

int main() {
  vi weights{1, 2, 3};
  vi values{10, 20, 29};

  lli res{max_value(weights, values, 3)};
  cout << "Max value with that capacity: " << res << '\n';

  return 0;
}
