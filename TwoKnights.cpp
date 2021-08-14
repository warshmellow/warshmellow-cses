#include <iostream>

using namespace std;

typedef long long ll;

void solve() {
  ll n;
  cin >> n;

  for (ll k = 1; k < n + 1; k++) {
    ll v = k * k * (k * k - 1) / 2 - 4 * (k - 1) * (k - 2);
    cout << v << "\n";
  }
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}