#include <bits/stdc++.h>
#define fore(x, a, b) for (int x = a, limit = b; x < limit; ++x)
using namespace std;
using vi = vector<int>;

int lis(vi& v) {
  int ans{0};
  vi maxs(v.size(), 1);

  fore(i, 0, v.size()) {
    fore(j, 0, i) {
      if (v[j] < v[i]) maxs[i] = max(maxs[i], maxs[j] + 1);
    }
    ans = max(ans, maxs[i]);
  }

  return ans;
}

int main() {
  vi nums{6, 2, 5, 1, 7, 4, 8, 3};
  cout << lis(nums) << '\n';

  return 0;
}
