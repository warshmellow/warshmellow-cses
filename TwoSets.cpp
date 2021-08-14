#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;

pair<vll, vll> g(ll n) {
  vll nums;
  for (ll i = 1; i < n + 1; i++) {
    nums.push_back(i);
  }

  vll a, b;
  ll sa = 0;
  ll sb = 0;

  for (int i = n - 1; i >= 0; i--) {
    ll num = nums[i];
    if (sa < sb) {
      a.push_back(num);
      sa += num;
    } else {
      b.push_back(num);
      sb += num;
    }
  }

  if (sa == sb) {
    return make_pair(a, b);
  } else {
    vll x, y;
    return make_pair(x, y);
  }
}

void solve() {
  ll n;
  cin >> n;

  pair<vll, vll> p = g(n);
  vll s1, s2;
  s1 = p.first;
  s2 = p.second;

  if (s1.size() > 0 && s2.size() > 0) {
    cout << "YES"
         << "\n";
    cout << s1.size() << "\n";
    for (size_t i = 0; i < s1.size() - 1; i++) {
      cout << s1[i] << " ";
    }
    cout << s1[s1.size() - 1] << "\n";

    cout << s2.size() << "\n";
    for (size_t i = 0; i < s2.size() - 1; i++) {
      cout << s2[i] << " ";
    }
    cout << s2[s2.size() - 1] << "\n";
  } else {
    cout << "NO"
         << "\n";
  }
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}