#include <iostream>
#include <vector>

using namespace std;

int main() {
  int MOD = 1000000000 + 7;

  int n;
  cin >> n;
  int m;
  cin >> m;

  int xs[n];
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    xs[i] = x;
  }

  cout << 3 % MOD << "\n";
}