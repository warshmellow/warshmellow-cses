#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

typedef long long ll;

int main() {
  ll n, t;
  cin >> n >> t;

  vector<ll> ks;
  vector<ll> tks;

  if (n == 1) {
    ll k;
    cin >> k;
    cout << k * t;
    return 0;
  }

  for (ll i = 0; i < n; i++) {
    ll k;
    cin >> k;
    ks.push_back(k);

    for (ll j = 1; j < t + 1; j++) {
      tks.push_back(j * k);
    }
  }

  sort(tks.begin(), tks.end());

  cout << tks[t - 1];

  // for time k,
  // start end is (0, k), (k, 2k), ... (lk, (l + 1)k)
  /*
    ks = 3, 2, 5

    count = 0
    (0, 2) -> count = 1
    (0, 3) -> count = 2
    (2, 4) -> count = 3
    (0, 5) -> count = 4
    (3, 6) -> count = 5
    (4, 6) -> count = 6
    (6, 8) -> count = 7

    one thing brute force is generate for each machine i,
    the intervals (0, k), (k, 2k), ..., ((t - 1)k, tk)
    Put all nt into a list, sort by end time, take first t.
    That is, generate pairs (k, 0), (2k, k), ..., (tk, (t-1)k)
    Or simply, k, 2k, ..., tk

    e.g.
    3, 6, 9
    2, 4, 6, 8
    5, 10

    -> (2, 3, 4, 5, 6, 6, 8)
  */
}