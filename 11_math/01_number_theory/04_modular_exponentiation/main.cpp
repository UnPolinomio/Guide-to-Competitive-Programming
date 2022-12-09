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

int main() {
  cout << modpow(2, 10, 1000000007) << '\n';
  return 0;
}
