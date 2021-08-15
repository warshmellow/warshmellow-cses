#include <iostream>

using namespace std;

typedef long long ll;

bool g(ll a, ll b) {
  ll three_x = 2 * a - b;
  ll three_y = 2 * b - a;
  return three_x >= 0 && three_y >= 0 && three_x % 3 == 0 && three_y % 3 == 0;
}

void solve() {
  size_t t;
  cin >> t;

  for (size_t i = 0; i < t; i++) {
    ll a, b;
    cin >> a >> b;
    if (g(a, b))
      cout << "YES\n";
    else
      cout << "NO\n";
  }
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return (0);
}