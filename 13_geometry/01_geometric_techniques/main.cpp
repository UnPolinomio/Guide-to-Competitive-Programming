#include <bits/stdc++.h>
#define fore(x, a, b) for (lli x = a, ___limit___ = b; x < ___limit___; ++x)
#define all(x) x.begin(), x.end()
#define deb(x) cout << #x << ": " << (x) << '\n';
using namespace std;
using lli = long long int;
using ii = pair<lli, lli>;
using ci = complex<long double>;
using vi = vector<lli>;
using vb = vector<bool>;

#define X real()
#define Y imag()

lli side(ci c1, ci c2) {
  auto cp{(conj(c1) * c2).Y};  // cross-product magnitude

  if (cp == 0) return 0;   // linearly dependent
  return cp > 0 ? 1 : -1;  // +1 = left, -1 = right
}

int main() {
  ci p1{3, 4};
  ci p2{5, 7};

  // Complex numbers
  p2 *= polar<long double>(1, M_PI / 2);  // rotate
  deb(p2);
  deb(abs(p2 - p1));
  deb(arg(p1) * 180 / M_PI);

  // Points and lines
  p2 = {5, 7};
  deb(side(p1, p2));

  ci p3{-1, -5};
  deb(side(p3 - p1, p3 - p2));  // Line p1 -> p2, +1 = left, -1 = right

  return 0;
}
