#include <bits/stdc++.h>
#define fore(x, a, b) for (lli x = a, ___limit___ = b; x < ___limit___; ++x)
#define all(x) x.begin(), x.end()
#define deb(x) cout << #x << ": " << (x) << '\n';
using namespace std;
using lli = long long int;
using ii = pair<lli, lli>;
using vi = vector<lli>;
using vb = vector<bool>;

struct SumQuery {
  vector<vi> prefix{};
  lli m{}, n{};

  SumQuery(const vector<vi>& matrix) {
    m = matrix.size();
    assert(m > 0);
    n = matrix[0].size();
    assert(n > 0);

    prefix.resize(m + 1, vi(n + 1, 0));
    fore(i, 1, m + 1) {
      lli curr{0};
      fore(j, 1, n + 1) {
        curr += matrix[i - 1][j - 1];
        prefix[i][j] = prefix[i - 1][j] + curr;
      }
    }
  }

  lli query(lli i1, lli j1, lli i2, lli j2) {
    assert(i1 >= 0 && i1 <= m && j1 >= 0 && j1 <= n);
    assert(i2 >= 0 && i2 <= m && j2 >= 0 && j2 <= n);
    return prefix[i2][j2] - prefix[i2][j1] - prefix[i1][j2] + prefix[i1][j1];
  }
};

int main() {
  vector<vi> matrix{{
      {1, 2, 3},  // 0
      {4, 5, 6},  // 1
      {7, 8, 9}   // 2
  }};
  SumQuery q(matrix);

  cout << "Prefixes: " << '\n';
  for (auto& row : q.prefix) {
    for (auto el : row) {
      cout << el << ' ';
    }
    cout << '\n';
  }
  cout << "\nQ: ( 2, 1 ) -> ( 3, 3 ) = 8 + 9 = " << q.query(2, 1, 3, 3) << '\n';

  return 0;
}
