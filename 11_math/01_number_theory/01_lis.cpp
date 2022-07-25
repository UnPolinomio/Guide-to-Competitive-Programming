#include <bits/stdc++.h>
#define fore(x, a, b) for (int x = a, limit = b; x < limit; ++x)
using namespace std;
using vi = vector<int>;

vi lis(vi& v) {
  int length{0};
  int index{-1};
  vi aux(v.size() + 1, -1);
  vi prev(v.size(), -1);

  fore(i, 0, v.size()) {
    auto it = lower_bound(
        aux.begin(), aux.begin() + length + 1, i,
        [&v](auto a, auto b) { return (a == -1 ? INT_MIN : v[a]) < v[b]; });
    int new_length = it - aux.begin();

    if (aux[new_length] == -1) {
      ++length;
      index = i;
    }
    if (aux[new_length] == -1 || v[i] < v[aux[new_length]]) {
      aux[new_length] = i;
    }
    prev[i] = aux[new_length - 1];
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
  for (int num : ans) cout << num << ' ';
  cout << '\n';

  return 0;
}
