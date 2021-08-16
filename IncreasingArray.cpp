#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;

ll g(vector<ll> nums) {
  ll total = 0;
  ll curr_max = nums[0];
  size_t n = nums.size();

  for (size_t i = 1; i < n; i++) {
    ll curr = nums[i];
    if (curr_max > curr) {
      ll diff = curr_max - curr;
      total += diff;
    }
    curr_max = max(curr_max, curr);
  }
  return total;
}

void solve() {
  size_t n;
  cin >> n;

  vector<ll> nums;
  for (size_t i = 0; i < n; i++) {
    ll x;
    cin >> x;
    nums.push_back(x);
  }
  cout << g(nums) << "\n";
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}