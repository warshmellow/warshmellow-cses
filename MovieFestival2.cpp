#include <algorithm>
#include <iostream>
#include <set>
#include <vector>
using namespace std;

typedef long long ll;

void solve() {
  size_t n, k;
  cin >> n >> k;
  vector<pair<ll, ll>> v(n);
  for (size_t i = 0; i < n; i++)  // read start time, end time
    cin >> v[i].second >> v[i].first;
  sort(v.begin(), v.end());  // sort by end time

  ll ans = 0;
  multiset<ll> end_times;  // times when members will finish watching movies
  for (size_t i = 0; i < k; i++) end_times.insert(0);

  for (size_t i = 0; i < n; i++) {
    auto it = end_times.upper_bound(v[i].second);
    if (it == end_times.begin()) continue;
    // assign movie to be watched by member in multiset who finishes at time
    // *prev(it)
    end_times.erase(next(it, -1));
    // member now finishes watching at time v[i].first
    end_times.insert(v[i].first);
    ans++;
  }

  cout << ans;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}