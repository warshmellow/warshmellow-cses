#include <iostream>
#include <vector>

using namespace std;

int main() {
  int MOD = 1000000000 + 7;

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

  int dp[n][x + 1];
  for (int i = 0; i < n; i++) dp[i][0] = 1;

  for (int j = 1; j < x + 1; j++) {
    if (j % coins[0] == 0)
      dp[0][j] = 1;
    else
      dp[0][j] = 0;
  }

  for (int i = 1; i < n; i++) {
    for (int j = 1; j < x + 1; j++) {
      if (j - coins[i] < 0)
        dp[i][j] = dp[i - 1][j];
      else
        dp[i][j] = dp[i][j - coins[i]] + dp[i - 1][j];

      dp[i][j] %= MOD;
    }
  }

  cout << dp[n - 1][x] << "\n";
}