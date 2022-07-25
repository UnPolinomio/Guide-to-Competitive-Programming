#include <bits/stdc++.h>
#define fore(x, a, b) for (int x = a, limit = b; x < limit; ++x)
using namespace std;
using vi = vector<int>;

int lis(vi& v) {
  int ans{0};
  vi aux(v.size() + 1, INT_MAX);
  aux[0] = INT_MIN;

  fore(i, 0, v.size()) {
    auto it{lower_bound(aux.begin(), aux.begin() + ans + 1, v[i])};
    int new_length = it - aux.begin();
    if (aux[new_length] == INT_MAX) ++ans;
    aux[new_length] = min(aux[new_length], v[i]);
  }

  return ans;
}

int main() {
  vi nums{6, 2, 5, 1, 7, 4, 8, 3};
  cout << lis(nums) << '\n';

  return 0;
}
