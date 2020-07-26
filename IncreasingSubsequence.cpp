#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
  int n;
  cin >> n;

  int nums[n];
  for (int i = 0; i < n; i++) {
    int num;
    cin >> num;
    nums[i] = num;
  }

  int dp[n];
  // dp[i] = longest increasing subequence ending at and including nums[i]
  // dp[0] = 1
  // max of dp is result
  dp[0] = 1;
  for (int i = 1; i < n; i++) {
    dp[i] = 1;

    for (int j = 0; j < i; j++) {
      if (nums[j] < nums[i]) {
        dp[i] = max(dp[i], dp[j] + 1);
      }
    }
  }

  int result = *max_element(dp, dp + n);

  cout << result << "\n";
}