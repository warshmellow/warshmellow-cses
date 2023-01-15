#include <iostream>

using namespace std;

typedef long long ll;

ll modpow(ll x, ll n, ll m) {
  if (n == 0) return 1 % m;

  ll u = modpow(x, n / 2, m);
  u = (u * u) % m;

  if (n % 2 == 1) u = (u * x) % m;

  return u;
}

int main() {
  ll MOD = 1000000000 + 7;

  int n;
  cin >> n;

  for (int i = 0; i < n; i++) {
    ll a;
    ll b;
    ll c;
    cin >> a;
    cin >> b;
    cin >> c;

    cout << modpow(a, modpow(b, c, MOD - 1), MOD) << "\n";
  }
}