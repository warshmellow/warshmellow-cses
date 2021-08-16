#include <math.h>

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;

ll f(ll n) {
  n--;
  ll digits = 1;
  while (true) {
    ll first = pow(10, digits - 1);
    if (n < 9 * first * digits) {
      return stoi(string(1, to_string(first + n / digits)[n % digits]));
    }
    n -= 9 * first * digits;
    digits++;
  }
}

void solve() {
  size_t q;
  cin >> q;
  for (size_t i = 0; i < q; i++) {
    ll k;
    cin >> k;
    cout << f(k) << "\n";
  }
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}