#include <iostream>

using namespace std;

typedef long long ll;

ll f(ll n, ll k) {
  ll count = 0;
  for (ll i = k; n / i >= 1; i *= k) {
    count += n / i;
  }
  return count;
}

void solve() {
  ll n;
  cin >> n;

  cout << min(f(n, 5), f(n, 2)) << "\n";
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return (0);
}