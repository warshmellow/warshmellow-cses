#include <math.h>

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;

ll f(ll n) {
  ll mod = 1000000000 + 7;
  if (n == 0) {
    return 1;
  }

  ll result = 2;
  for (ll i = 1; i < n; i++) {
    result = (result * 2) % mod;
  }
  return result;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  ll n;
  cin >> n;

  ll result = f(n);

  cout << result << "\n";
}