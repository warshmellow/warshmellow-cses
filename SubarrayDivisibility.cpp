#include <algorithm>
#include <iostream>
#include <map>
#include <set>
#include <vector>

typedef long long ll;

using namespace std;

ll g(vector<ll> a) {
  map<ll, ll> h;
  h[0] = 1;

  int n = a.size();

  ll count = 0;
  ll curr = 0;

  for (int i = 0; i < n; i++) {
    ll p = curr;
    p %= n;

    curr += a[i];
    curr %= n;

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

  vector<ll> a;
  for (int i = 0; i < n; i++) {
    ll ai;
    cin >> ai;
    a.push_back(ai);
  }

  cout << g(a) << "\n";
}