#include <math.h>

#include <algorithm>
#include <deque>
#include <iostream>
#include <map>
#include <set>
#include <vector>

using namespace std;

typedef long long ll;

vector<string> f(string s) {
  size_t n = s.size();
  if (n == 0)
    return {};
  else if (n == 1)
    return {s};

  vector<string> prev = f(s.substr(1));
  set<string> result_set;

  for (string p : prev) {
    string curr(1, s[0]);
    for (size_t i = 0; i < n; i++) {
      string candidate = p.substr(0, i) + curr + p.substr(i, n - 1);
      result_set.insert(candidate);
    }
  }

  vector<string> result(result_set.begin(), result_set.end());
  return result;
}

void solve() {
  string s;
  cin >> s;

  vector<string> result = f(s);
  sort(result.begin(), result.end());

  cout << result.size() << "\n";
  for (string s : result) {
    cout << s << "\n";
  }
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return (0);
}