#include <math.h>

#include <algorithm>
#include <iostream>
#include <map>
#include <set>
#include <vector>

using namespace std;

typedef long long ll;

void solve() {
  size_t n, m;
  ll k;
  cin >> n >> m >> k;

  vector<ll> a;
  vector<ll> b;

  for (size_t i = 0; i < n; i++) {
    ll x;
    cin >> x;
    a.push_back(x);
  }

  for (size_t i = 0; i < m; i++) {
    ll x;
    cin >> x;
    b.push_back(x);
  }

  sort(a.begin(), a.end());
  sort(b.begin(), b.end());

  size_t i = 0;
  size_t j = 0;

  size_t count = 0;

  while (i < n && j < m) {
    ll ai, bj;
    ai = a[i];
    bj = b[j];

    if (bj - k <= ai && ai <= bj + k) {
      count++;
      i++;
      j++;
    } else if (ai < bj - k) {
      i++;
    } else if (bj + k < ai) {
      j++;
    }
  }
  cout << count << "\n";
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}