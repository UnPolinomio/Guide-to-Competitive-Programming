#include <bits/stdc++.h>
#define fore(x, a, b) for (lli x = a, ___limit___ = b; x < ___limit___; ++x)
#define all(x) x.begin(), x.end()
#define deb(x) cout << #x << ": " << (x) << '\n';
using namespace std;
using lli = long long int;
using ii = pair<lli, lli>;
using vi = vector<lli>;
using vb = vector<bool>;

lli modpow(lli a, lli b, lli m) {
  if (b == 0) return 1;

  lli tmp{modpow(a, b / 2, m)};
  tmp *= tmp;
  tmp %= m;

  if (b & 1) {
    tmp *= a;
    tmp %= m;
  }

  return tmp;
}

pair<lli, lli> chinese_remainder_theorem(
    vector<pair<lli, lli>> system) {  // vector<[a, p_i]>
  lli x{0};
  lli M{1};

  for (auto& el : system) M *= el.second;

  for (auto [a, m] : system) {
    lli d{M / m};
    lli d_i{modpow(d, m - 2, M)};  // TODO: make it work for non-prime mods

    lli tmp{d * d_i};
    tmp %= M;
    tmp *= a % M;
    tmp %= M;

    x += tmp;
    x %= M;
  }

  return {x, M};
}

int main() {
  auto ans{chinese_remainder_theorem({{0, 2}, {2, 3}, {3, 5}, {4, 7}})};
  printf("x = %lli (mod %lli)\n", ans.first, ans.second);
  return 0;
}
