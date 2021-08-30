#include <math.h>

#include <algorithm>
#include <iostream>
#include <map>
#include <set>
#include <vector>

using namespace std;

typedef long long ll;

void solve() {
  int n;
  cin >> n;
  vector<ll> v(n);

  for (int i = 0; i < n; i++) {
    cin >> v[i];
  }

  sort(v.begin(), v.end());

  ll mid = v[n / 2];
  ll ans = 0;

  for (ll i : v) {
    ans += abs(i - mid);
  }
  cout << ans << "\n";
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}