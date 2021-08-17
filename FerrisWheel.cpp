#include <math.h>

#include <algorithm>
#include <deque>
#include <iostream>
#include <map>
#include <set>
#include <vector>

using namespace std;

typedef long long ll;

void solve() {
  size_t n, x;
  cin >> n >> x;

  vector<ll> ps;
  for (size_t i = 0; i < n; i++) {
    ll y;
    cin >> y;
    ps.push_back(y);
  }

  sort(ps.begin(), ps.end());
  deque<ll> d(ps.begin(), ps.end());

  ll ans = 0;
  while (d.size() >= 1) {
    ans++;
    if (d.size() == 1)
      break;
    else if (d[0] + d[d.size() - 1] > x) {
      d.pop_back();
    } else {
      d.pop_back();
      d.pop_front();
    }
  }
  cout << ans << "\n";
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}