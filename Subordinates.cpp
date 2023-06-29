#include <algorithm>
#include <iostream>
#include <map>
#include <set>
#include <vector>

using namespace std;

typedef long long ll;
typedef vector<ll> vll;

ll count_subs(map<ll, vll> adj, ll boss) {
  vll direct_subs = adj[boss];

  ll total = 0;
  for (int i = 0; i < direct_subs.size(); i++) {
    ll direct_sub = direct_subs[i];
    total += 1 + count_subs(adj, direct_sub);
  }
  return total;
}

vll g(vll bosses) {
  map<ll, vll> adj;

  int n = bosses.size() + 1;

  for (ll i = 0; i < bosses.size(); i++) {
    ll sub = i + 2;
    ll boss = bosses[i];

    if (adj.find(boss) == adj.end()) {
      adj[boss] = vll();
    }

    adj[boss].push_back(sub);
  }

  vll result;
  for (ll i = 1; i < n + 1; i++) {
    result.push_back(count_subs(adj, i));
  }
  return result;
}

int main() {
  int n;
  cin >> n;

  vll bosses;
  for (int i = 0; i < n - 1; i++) {
    ll ai;
    cin >> ai;
    bosses.push_back(ai);
  }

  vll result = g(bosses);

  for (int i = 0; i < n; i++) {
    cout << result[i] << " ";
  }
}