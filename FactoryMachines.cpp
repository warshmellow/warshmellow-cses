#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

typedef long long ll;

ll valid(ll t, ll T, const vector<ll> &ks) {
  ll count = 0;
  int n = ks.size();
  for (int i = 0; i < n; i++) {
    count += t / ks[i];
    if (count >= T) {
      return true;
    }
  }
  return false;
}

int main() {
  ll n, t;
  cin >> n >> t;

  vector<ll> ks;

  if (n == 1) {
    ll k;
    cin >> k;
    cout << k * t;
    return 0;
  }

  for (ll i = 0; i < n; i++) {
    ll k;
    cin >> k;
    ks.push_back(k);
  }

  ll lo = 0;
  ll hi = 1e18;
  while (lo <= hi) {
    ll mid = lo + (hi - lo) / 2;
    if (valid(mid, t, ks)) {
      hi = mid - 1;
    } else {
      lo = mid + 1;
    }
  }
  cout << lo;
}