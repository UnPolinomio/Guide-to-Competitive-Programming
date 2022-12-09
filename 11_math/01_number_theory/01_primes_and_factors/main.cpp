#include <bits/stdc++.h>
#define fore(x, a, b) for (lli x = a, ___limit___ = b; x < ___limit___; ++x)
#define all(x) x.begin(), x.end()
#define deb(x) cout << #x << ": " << (x) << '\n';
using namespace std;
using lli = long long int;
using ii = pair<lli, lli>;
using vi = vector<lli>;
using vb = vector<bool>;

#define LIMIT 100000000

vi primes_1(lli n) {  // O(sqrt (n) )
  vi p{};

  for (lli x{2}; x * x <= n; ++x) {
    while (n % x == 0) {
      p.push_back(x);
      n /= x;
    }
  }

  if (n > 1) p.push_back(n);
  return p;
}

vi sieve_min_prime(lli n) {  // O(n log n)
  vi s(n + 1ll, true);
  s[0] = 0, s[1] = 0;

  for (lli x{2}; x <= n; ++x) s[x] = x;

  for (lli x{2}; x * x <= n; ++x) {
    if (s[x] != x) continue;

    for (lli d{x * x}; d <= n; d += x)
      if (d == s[d]) s[d] = x;
  }

  return s;
}

vi primes_2(lli n) {  // O(LIMIT log LIMIT + log n)
  if (n == 0) return {};

  static vi s{};
  if (s.size() == 0) s = sieve_min_prime(LIMIT);

  vi ans{};
  if (n < 0) {
    ans.push_back(-1);
    n *= -1;
  }

  while (n != 1) {
    ans.push_back(s[n]);
    n /= s[n];
  }

  return ans;
}

int main() {
  for (auto el : primes_1(8954324)) cout << el << " ";
  cout << '\n';
  for (auto el : primes_2(8954324)) cout << el << " ";  // FIX order
  cout << '\n';
  return 0;
}
