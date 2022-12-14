#include <bits/stdc++.h>
#define fore(x, a, b) for (lli x = a, ___limit___ = b; x < ___limit___; ++x)
#define all(x) x.begin(), x.end()
#define deb(x) cout << #x << ": " << (x) << '\n';
using namespace std;
using lli = long long int;
using ii = pair<lli, lli>;
using vi = vector<lli>;
using vb = vector<bool>;

struct SegmentTree {
  vi t{};
  lli n{};

  SegmentTree(initializer_list<lli> l) {
    n = l.size();
    t.resize(2 * n);
    copy(all(l), t.begin() + n);
    for (lli i{n - 1}; i > 0; --i) t[i] = t[i << 1] + t[i << 1 | 1];
  }

  void update(lli i, lli v) {
    i += n;
    t[i] = v;
    for (i >>= 1; i > 0; i >>= 1) t[i] = t[i << 1] + t[i << 1 | 1];
  }

  lli query(lli l, lli r) {
    l += n, r += n;
    lli ans{0};

    while (l <= r) {
      if (l & 1) ans += t[l++];
      if (!(r & 1)) ans += t[r--];
      l >>= 1, r >>= 1;
    }

    return ans;
  }
};

int main() {
  SegmentTree st{{1, 2, 3, 4}};
  st.update(2, 10);   // st = {1, 2, 10, 4}
  st.update(0, 500);  // st = {500, 2, 10, 4}
  cout << st.query(0, 3) << '\n';
  cout << st.query(1, 2) << '\n';
  cout << st.query(0, 0) << '\n';
  cout << st.query(3, 3) << '\n';
  cout << st.query(2, 2) << '\n';
  return 0;
}
