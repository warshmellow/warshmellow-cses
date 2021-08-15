#include <math.h>

#include <algorithm>
#include <deque>
#include <iostream>
#include <map>
#include <set>
#include <vector>

using namespace std;

typedef long long ll;

vector<string> g(ll n) {
  if (n == 1) {
    return {"0", "1"};
  } else {
    vector<string> prev = g(n - 1);
    vector<string> result;
    for (string s : prev) {
      result.push_back("0" + s);
    }

    vector<string> rev_prev(prev.rbegin(), prev.rend());

    for (string s : rev_prev) {
      result.push_back("1" + s);
    }
    return result;
  }
}

void solve() {
  ll n;
  cin >> n;

  for (string s : g(n)) {
    cout << s << "\n";
  }
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return (0);
}