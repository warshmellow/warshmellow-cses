#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
  int MOD = 1000000000 + 7;

  int n;
  cin >> n;

  bool grid[n][n];
  int dp[n][n];
  int count = n;

  for (int i = 0; i < count; i++) {
    string curr;
    cin >> curr;

    for (int j = 0; j < count; j++) {
      grid[i][j] = curr.substr(j, 1) == "*";
    }
  }

  if (grid[0][0] || grid[n - 1][n - 1]) {
    cout << 0 << "\n";
    return 0;
  }

  for (int i = 0; i < count; i++) {
    for (int j = 0; j < count; j++) {
      dp[i][j] = 0;
    }
  }

  dp[n - 1][n - 1] = 1;

  bool trap_seen = false;
  for (int i = count - 1; i > -1; i--) {
    if (grid[i][count - 1] || trap_seen) {
      trap_seen = true;
      dp[i][count - 1] = 0;
    } else {
      dp[i][count - 1] = 1;
    }
  }

  trap_seen = false;
  for (int j = count - 1; j > -1; j--) {
    if (grid[count - 1][j] || trap_seen) {
      trap_seen = true;
      dp[count - 1][j] = 0;
    } else {
      dp[count - 1][j] = 1;
    }
  }

  for (int i = count - 2; i > -1; i--) {
    for (int j = count - 2; j > -1; j--) {
      if (grid[i][j]) {
        dp[i][j] = 0;
      } else {
        dp[i][j] = dp[i + 1][j] + dp[i][j + 1];
        dp[i][j] %= MOD;
      }
    }
  }

  cout << dp[0][0] % MOD << "\n";
}