#include <algorithm>
#include <ext/pb_ds/assoc_container.hpp>
#include <iostream>
#include <vector>

using namespace std;
using namespace __gnu_pbds;

typedef long long ll;
typedef tree<ll, null_type, less<ll>, rb_tree_tag,
             tree_order_statistics_node_update>
    indexed_set;

vector<ll> josh(indexed_set &person, ll k) {
  vector<ll> result;
  ll index = 0;

  for (ll n = person.size(); n > 1; n--) {
    index = (index + k) % n;
    result.push_back(*person.find_by_order(index));
    person.erase(*person.find_by_order(index));
  }
  result.push_back(*person.begin());
  return result;
}

void solve() {
  ll n, k;
  cin >> n >> k;

  indexed_set person;
  for (ll i = 1; i < n + 1; i++) {
    person.insert(i);
  }

  for (ll x : josh(person, k)) {
    cout << x << " ";
  }
  cout << "\n";
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}