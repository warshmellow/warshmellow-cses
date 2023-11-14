#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;

const ll MOD = 1000000000 + 7;
const ll MAXN = 1000000;

vector<ll> factorial(MAXN + 1, 0);

ll binpow(ll a, ll b, ll m) {
  a %= m;
  ll res = 1;
  while (b > 0) {
    if (b & 1) res = res * a % m;
    a = a * a % m;
    b >>= 1;
  }
  return res;
}

ll inverse(ll a) { return binpow(a, MOD - 2, MOD); }

ll f(ll n, ll k) {
  if (k == 0 || k == n) {
    return 1;
  }
  return factorial[n] * inverse(factorial[k] * factorial[n - k] % MOD) % MOD;
}

int main() {
  factorial[0] = 1;
  for (ll i = 1; i < MAXN + 1; i++) {
    factorial[i] = factorial[i - 1] * i % MOD;
  }

  int n;
  cin >> n;

  for (int i = 0; i < n; i++) {
    ll a;
    ll b;
    cin >> a;
    cin >> b;

    cout << f(a, b) << "\n";
  }
}
