#include <algorithm>
#include <iostream>
#include <vector>

typedef long long ll;

using namespace std;

ll f(vector<ll> arr) {
  ll res = 1;
  int n = arr.size();

  for (int i = 0; i < n && arr[i] <= res; i++) {
    res = res + arr[i];
  }
  return res;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n;
  cin >> n;

  vector<ll> nums;

  for (int i = 0; i < n; i++) {
    ll x;
    cin >> x;
    nums.push_back(x);
  }

  sort(nums.begin(), nums.end());

  cout << f(nums) << "\n";
}