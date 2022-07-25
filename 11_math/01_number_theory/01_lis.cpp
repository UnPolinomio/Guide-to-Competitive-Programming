#include <bits/stdc++.h>
#define fore(x, a, b) for (int x = a, limit = b; x < limit; ++x)
using namespace std;
using vi = vector<int>;

vi lis(vi& v) {
  if (v.size() == 0) return {};

  int index{0};
  vi maxs(v.size(), 1);
  vi prev(v.size(), -1);

  fore(i, 0, v.size()) {
    fore(j, 0, i) {
      if (v[j] >= v[i] || maxs[j] < maxs[i]) continue;
      maxs[i] = maxs[j] + 1;
      prev[i] = j;
    }
    if (maxs[i] <= maxs[index]) continue;
    index = i;
  }

  vi ans{};
  while (index != -1) {
    ans.push_back(v[index]);
    index = prev[index];
  }
  reverse(ans.begin(), ans.end());

  return ans;
}

int main() {
  vi nums{6, 2, 5, 1, 7, 4, 8, 3};
  vi ans{lis(nums)};
  for (int num : ans) {
    cout << num << ' ';
  }
  cout << '\n';

  return 0;
}
