#include <iostream>
#include <map>
#include <queue>
#include <vector>

using namespace std;

typedef long long ll;

int main() {
  int n;
  cin >> n;

  vector<ll> ks;
  for (int i = 0; i < n; i++) {
    ll k;
    cin >> k;
    ks.push_back(k);
  }

  int ans = 1;
  map<ll, int> mp;

  mp[ks[0]] = 0;

  int i = 0;
  for (int j = 1; j < n; j++) {
    ll k = ks[j];

    if (mp.count(k)) {
      i = max(mp[k] + 1, i);
    }

    ans = max(ans, j + 1 - i);
    mp[k] = j;
  }

  cout << ans;
}