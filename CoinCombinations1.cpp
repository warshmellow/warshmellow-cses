#include <iostream>
#include <vector>

using namespace std;

int main() {
  int MOD = 1000000000 + 7;

  int n;
  cin >> n;
  int x;
  cin >> x;

  vector<int> coins;
  for (int i = 0; i < n; i++) {
    int coin;
    cin >> coin;
    coins.push_back(coin);
  }

  vector<int> count(x + 1, 0);
  count[0] = 1;
  for (int i = 1; i <= x; i++) {
    for (auto c : coins) {
      if (i - c >= 0) {
        count[i] += count[i - c];
        count[i] %= MOD;
      }
    }
  }

  cout << count[x] << "\n";
}