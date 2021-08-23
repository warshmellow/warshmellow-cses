#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

void solve() {
  int mod = 1e9 + 7;
  int n;
  cin >> n;

  int total = n * (n + 1) / 2;

  if (total % 2 != 0) {
    cout << 0 << "\n";
    return;
  }
  int target = total / 2;

  vector<vector<int>> dp(n, vector<int>(target + 1, 0));
  dp[0][0] = 1;

  for (int i = 1; i < n; i++) {
    for (int j = 0; j <= target; j++) {
      dp[i][j] = dp[i - 1][j];
      if (j - i >= 0) {
        dp[i][j] = (dp[i][j] + dp[i - 1][j - i]) % mod;
      }
    }
  }

  cout << dp[n - 1][target] << "\n";
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}