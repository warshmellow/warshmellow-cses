#include <math.h>

#include <algorithm>
#include <functional>
#include <iostream>
#include <numeric>
#include <vector>

using namespace std;

typedef long long ll;

vector<vector<ll>> get_subsets(vector<ll> nums) {
  size_t n = nums.size();
  if (n == 1) {
    vector<ll> nums_copy(nums);
    return {{}, nums_copy};
  }

  vector<ll> second_slice(nums.begin() + 1, nums.end());

  vector<vector<ll>> prev = get_subsets(second_slice);

  vector<vector<ll>> result;
  for (vector<ll> subset : prev) {
    vector<ll> candidate{nums[0]};
    candidate.insert(candidate.end(), subset.begin(), subset.end());

    result.push_back(candidate);
  }

  result.insert(result.end(), prev.begin(), prev.end());

  return result;
}

ll f(vector<ll> nums) {
  ll total = 0;
  for (ll num : nums) {
    total += num;
  }

  vector<vector<ll>> subsets = get_subsets(nums);

  vector<ll> vals;
  for (vector<ll> subset : subsets) {
    ll sum_subset = 0;

    for (ll x : subset) {
      sum_subset += x;
    }

    vals.push_back(abs(total - 2 * sum_subset));
  }
  return *min_element(vals.begin(), vals.end());
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
  cout << f(nums) << "\n";
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return (0);
}