#include <iostream>
#include <vector>

using namespace std;

int MOD = 1000000000 + 7;

int f(vector<int> xs, int m) {
  int n = xs.size();
  if (n == 0) {
    return 1;
  } else if (n == 1 && xs[0] == 0) {
    if (xs[0] == 0)
      return m + 1;
    else
      return 1;
  } else if (n == 2) {
    return 0;
  }
  return 0;
}

int main() {
  int n;
  cin >> n;
  int m;
  cin >> m;

  vector<int> xs;
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    xs.push_back(x);
  }

  cout << f(xs, m) % MOD << "\n";
}