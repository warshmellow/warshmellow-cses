#include <algorithm>
#include <iostream>
#include <set>
#include <vector>

using namespace std;

vector<int> f(vector<int> xs) {
  int n = xs.size();
  vector<int> result;

  if (n == 0) {
    return result;
  } else if (n == 1) {
    result.push_back(xs[0]);
    return result;
  }

  int curr = xs[0];
  vector<int> rest = vector<int>(xs.begin() + 1, xs.end());

  vector<int> prev = f(rest);
  set<int> rset{curr};

  for (auto psum : prev) {
    rset.insert(curr + psum);
    rset.insert(psum);
  }

  for (auto x : rset) {
    result.push_back(x);
  }

  sort(result.begin(), result.end());
  return result;
}

int main() {
  int n;
  cin >> n;

  vector<int> xs;
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    xs.push_back(x);
  }

  vector<int> results = f(xs);

  int k = results.size();
  cout << k << "\n";

  for (int i = 0; i < k; i++) {
    cout << results[i] << " ";
  }

  cout << "\n";
}