#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;

pair<ll, ll> g(vector<ll> a, ll x) {
  size_t n = a.size();

  vector<pair<ll, size_t>> a_with_idx;
  for (size_t i = 0; i < n; i++) {
    a_with_idx.push_back(make_pair(a[i], i));
  }
  sort(a_with_idx.begin(), a_with_idx.end());

  for (pair<ll, size_t> p : a_with_idx) {
    ll y = p.first;
    size_t i = p.second;

    ll diff = x - y;

    auto it = lower_bound(a_with_idx.begin(), a_with_idx.end(),
                          make_pair(diff, n + 1));
    size_t j = it - a_with_idx.begin();
    if (j > 0) {
      pair<ll, size_t> pcand = a_with_idx[j - 1];
      ll cand = pcand.first;
      size_t cand_idx = pcand.second;
      if (cand == diff && cand_idx > i) {
        return make_pair(i + 1, cand_idx + 1);
      }
    }
  }

  return make_pair(-1, -1);
}

void solve() {
  size_t n;
  ll x;
  vector<ll> a;

  cin >> n >> x;

  for (size_t i = 0; i < n; i++) {
    ll y;
    cin >> y;
    a.push_back(y);
  }

  pair<ll, ll> p = g(a, x);
  if (p.first == -1) {
    cout << "IMPOSSIBLE\n";
  } else {
    cout << p.first << " " << p.second << "\n";
  }
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}