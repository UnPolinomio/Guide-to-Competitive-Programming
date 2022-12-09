#include <bits/stdc++.h>
#define fore(x, a, b) for (lli x = a, ___limit___ = b; x < ___limit___; ++x)
#define all(x) x.begin(), x.end()
#define deb(x) cout << #x << ": " << (x) << '\n';
using namespace std;
using lli = long long int;
using ii = pair<lli, lli>;
using vi = vector<lli>;
using vb = vector<bool>;

tuple<lli, lli, lli> gcd(lli a, lli b) {
  if (b == 0) return {1, 0, a};

  auto [x, y, d] = gcd(b, a % b);
  return {y, x - y * (a / b), d};
}

int main() {
  lli a{6000000}, b{101};
  auto [x, y, d]{gcd(a, b)};
  printf("%lli x %lli + %lli x %lli = gcd(%lli, %lli) = %lli\n", x, a, y, b, a,
         b, d);
  return 0;
}
