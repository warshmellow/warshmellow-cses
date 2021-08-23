#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

void solve() {
  int n;
  cin >> n;
  vector<int> dp;

  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    auto it = lower_bound(dp.begin(), dp.end(), x);
    if (it == dp.end()) {
      dp.push_back(x);
    } else {
      *it = x;
    }
  }

  cout << dp.size() << "\n";
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}