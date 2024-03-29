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

ll binom(ll n, ll k) {
  if (k == 0 || k == n) {
    return 1;
  }
  return factorial[n] * inverse(factorial[k] * factorial[n - k] % MOD) % MOD;
}

ll c(ll n) { return inverse(n + 1) * binom(2 * n, n) % MOD; }

ll bracket_sequences(ll n) {
  if (n % 2 == 1) {
    return 0;
  }
  return c(n / 2);
}

int main() {
  factorial[0] = 1;
  for (ll i = 1; i < MAXN + 1; i++) {
    factorial[i] = factorial[i - 1] * i % MOD;
  }

  ll n;
  cin >> n;

  cout << bracket_sequences(n);
}
