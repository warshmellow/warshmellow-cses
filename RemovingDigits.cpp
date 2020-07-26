#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
  int n;
  cin >> n;

  int dp[n + 1];
  dp[0] = 0;

  for (int i = 1; i < n + 1; i++) {
    string as_string = to_string(i);

    int min_length = INT32_MAX;
    for (size_t j = 0; j < as_string.size(); j++) {
      string c = as_string.substr(j, 1);

      int x = stoi(c);
      if (x > 0) {
        min_length = min(min_length, 1 + dp[i - x]);
      }
    }
    dp[i] = min_length;
  }

  cout << dp[n] << "\n";
}