#include <algorithm>
#include <iostream>
#include <vector>
#include <set>

typedef long long ll;

using namespace std;

void solve() {
  int n, a, b;

  cin >> n >> a >> b;

  vector<ll> prefixes = {0};
  multiset<ll> mset;

  for(int i = 1; i < n + 1; i++){
    int x;
    cin >> x;

    prefixes.push_back(prefixes[i - 1] + x);
  }

  for(int i = a; i < b + 1; i++) {
    mset.insert(prefixes[i]);
  }

  ll best = *mset.rbegin();
  for(int i = 1; i + a < n + 1; i++) {
    mset.erase(prefixes[i + a - 1]);
    if(i + b < n + 1) {
        mset.insert(prefixes[i + b]);
    }
    best = max(best, *mset.rbegin() - prefixes[i]);
  }

  cout << best << "\n";
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}