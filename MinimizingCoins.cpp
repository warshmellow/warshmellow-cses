#include <iostream>
#include <vector>

using namespace std;

int f(vector<int> coins, int x) {
  int n = coins.size();
  int MAX = INT32_MAX;

  int dp[n + 1][x + 1];

  for (int j = 1; j < x + 1; j++) {
    dp[0][j] = MAX;
  }

  for (int i = 1; i < n + 1; i++) {
    for (int j = 1; j < x + 1; j++) {
      if (coins[i - 1] == j) {
        dp[i][j] = 1;
      } else if (coins[i - 1] > j) {
        dp[i][j] = dp[i - 1][j];
      } else if (dp[i][j - coins[i - 1]] < MAX) {
        dp[i][j] = min(dp[i - 1][j], 1 + dp[i][j - coins[i - 1]]);
      } else {
        dp[i][j] = dp[i - 1][j];
      }
    }
  }
  return dp[n][x];
}

int main() {
  int n;
  cin >> n;
  int x;
  cin >> x;

  vector<int> coins;
  for (int i = 0; i < n; i++) {
    int coin;
    cin >> coin;
    coins.push_back(coin);
  }

  int result = f(coins, x);

  if (result == INT32_MAX) {
    cout << "-1"
         << "\n";
  } else {
    cout << result << "\n";
  }
}