#include <algorithm>
#include <iostream>
#include <map>
#include <set>
#include <vector>

typedef long long ll;

using namespace std;

int g(ll x, vector<ll> a) {
  map<ll, int> h;
  h[0] = 1;

  int n = a.size();

  int count = 0;
  ll curr = 0;

  for (int i = 0; i < n; i++) {
    curr += a[i];
    ll p = curr - x;

    if (h.count(p)) count += h[p];

    if (h.count(curr))
      h[curr]++;
    else
      h[curr] = 1;
  }

  return count;
}

int main() {
  int n;
  cin >> n;
  ll x;
  cin >> x;

  vector<ll> a;
  for (int i = 0; i < n; i++) {
    ll ai;
    cin >> ai;
    a.push_back(ai);
  }

  cout << g(x, a) << "\n";
}