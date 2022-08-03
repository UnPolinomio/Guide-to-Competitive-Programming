#include <bits/stdc++.h>
#define fore(x, a, b) for (lli x = a, limit = b; x < limit; ++x)
#define all(x) x.begin(), x.end()
using namespace std;
using lli = long long int;
using ii = pair<lli, lli>;
using vi = vector<lli>;
using vb = vector<bool>;

vi all_possible_sums(vi& weights) {
  lli total = accumulate(all(weights), 0ll);
  vb possible(total + 1ll, false);
  possible[0] = true;

  for (lli w : weights) {
    for (lli i = total - w; i >= 0; --i) {
      possible[i + w] = possible[i + w] || possible[i];
    }
  }

  vi ans{};
  fore(i, 0, possible.size()) {
    if (possible[i]) ans.push_back(i);
  }
  return ans;
}

int main() {
  vi weights{1, 3, 3, 5};
  vi possible{all_possible_sums(weights)};

  for (lli p : possible) cout << p << ' ';
  cout << '\n';

  return 0;
}
