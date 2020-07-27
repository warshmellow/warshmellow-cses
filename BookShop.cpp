#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
  int n;
  int x;
  cin >> n;
  cin >> x;

  int h[n];
  int s[n];
  int count = n;

  for (int i = 0; i < count; i++) {
    int hi;
    cin >> hi;
    h[i] = hi;
  }

  for (int i = 0; i < count; i++) {
    int si;
    cin >> si;
    s[i] = si;
  }

  int dp[n][x + 1];
  for (int i = 0; i < count; i++) {
    dp[i][0] = 0;
  }
  for (int j = 0; j < x + 1; j++) {
    if (h[0] <= j)
      dp[0][j] = s[0];
    else
      dp[0][j] = 0;
  }

  for (int i = 1; i < count; i++) {
    for (int j = 1; j < x + 1; j++) {
      if (j - h[i] >= 0)
        dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - h[i]] + s[i]);
      else
        dp[i][j] = dp[i - 1][j];
    }
  }

  cout << dp[n - 1][x] << "\n";
}