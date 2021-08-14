#include <iostream>

using namespace std;

typedef long long ll;

ll get_y_edge(ll y) {
  if (y % 2 == 0)
    return y * y;
  else
    return (y - 1) * (y - 1) + 1;
}

ll get_x_edge(ll x) {
  if (x % 2 == 0)
    return (x - 1) * (x - 1) + 1;
  else
    return x * x;
}

ll g(ll y, ll x) {
  if (x == 1) {
    return get_y_edge(y);
  } else if (y == 1) {
    return get_x_edge(x);
  } else if (x == y) {
    ll valy = get_y_edge(y);
    ll valx = get_x_edge(x);
    ll mn = min(valy, valx);
    ll mx = max(valy, valx);
    return mn + (mx - mn) / 2;
  } else if (y > x) {
    ll start = get_y_edge(y);
    if (y % 2 == 0)
      return start - x + 1;
    else
      return start + x - 1;
  } else {
    ll start = get_x_edge(x);
    if (x % 2 == 0)
      return start + y - 1;
    else
      return start - y + 1;
  }
}

void solve() {
  size_t t;
  cin >> t;

  for (size_t i = 0; i < t; i++) {
    ll y, x;
    cin >> y >> x;
    cout << g(y, x) << "\n";
  }
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}