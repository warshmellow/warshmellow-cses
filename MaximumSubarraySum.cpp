#include <algorithm>
#include <iostream>
#include <vector>

typedef long long ll;

using namespace std;

void solve() {
  size_t n;
  cin >> n;

  vector<ll> nums;
  for (size_t i = 0; i < n; i++) {
    ll num;
    cin >> num;
    nums.push_back(num);
  }

  ll max_so_far = nums[0];
  ll max_curr = nums[0];

  for (size_t i = 1; i < n; i++) {
    ll curr = nums[i];
    max_curr = max(max_curr + curr, curr);
    max_so_far = max(max_so_far, max_curr);
  }

  cout << max_so_far << "\n";
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}