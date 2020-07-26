#include <algorithm>
#include <iostream>
#include <vector>

typedef long long ll;

using namespace std;

ll f(ll nums[], int n) {
  ll max_so_far = nums[0];
  ll max_curr = nums[0];

  for (int i = 1; i < n; i++) {
    ll curr = nums[i];
    max_curr = max(max_curr + curr, curr);
    max_so_far = max(max_so_far, max_curr);
  }
  return max_so_far;
}

int main() {
  int n;
  cin >> n;

  ll nums[n];
  for (int i = 0; i < n; i++) {
    ll num;
    cin >> num;
    nums[i] = num;
  }

  ll result = f(nums, n);

  cout << result << "\n";
}