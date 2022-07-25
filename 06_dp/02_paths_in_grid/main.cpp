#include <bits/stdc++.h>
#define fore(x, a, b) for (lli x = a, limit = b; x < limit; ++x)
using namespace std;
using lli = long long int;
using ii = pair<lli, lli>;
using vi = vector<lli>;

using board_t = vector<vi>;

vector<ii> max_path(board_t& board) {
  if (board.size() == 0 || board[0].size() == 0) return {};

  int n = board.size();
  int m = board[0].size();

  board_t dp(n, vi(m, 0));
  vector<vector<ii>> prev(n, vector<ii>(m));

  dp[0][0] = board[0][0];
  fore(i, 0, n) {
    fore(j, 0, m) {
      if (i + j == 0) continue;

      if (i == 0) {
        dp[i][j] = board[i][j] + dp[i][j - 1];
        prev[i][j] = make_pair(i, j - 1);
        continue;
      }

      if (j == 0) {
        dp[i][j] = board[i][j] + dp[i - 1][j];
        prev[i][j] = make_pair(i - 1, j);
        continue;
      }

      if (board[i][j - 1] > board[i - 1][j])
        prev[i][j] = make_pair(i, j - 1);
      else
        prev[i][j] = make_pair(i - 1, j);

      dp[i][j] = board[i][j] + max(board[i - 1][j], board[i][j - 1]);
    }
  }

  n--;
  m--;
  vector<ii> ans{};
  while (n + m > 0) {
    ans.emplace_back(n, m);
    tie(n, m) = prev[n][m];
  }
  reverse(ans.begin(), ans.end());
  return ans;
}

int main() {
  board_t board{{{3, 7, 9, 2, 7},
                 {9, 8, 3, 5, 5},
                 {1, 7, 9, 8, 5},
                 {3, 8, 6, 4, 10},
                 {6, 3, 9, 7, 8}}};

  auto ans{max_path(board)};
  for (auto& p : ans) {
    printf("( %lli, %lli )\n", p.first, p.second);
  }

  return 0;
}
