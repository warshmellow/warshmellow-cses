#include <iostream>
#include <vector>

using namespace std;

int INF = INT32_MAX;

int main() {
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

  vector<int> value(x + 1, 0);
  value[0] = 0;
  for (int i = 1; i <= x; i++) {
    value[i] = INF;
    for (auto c : coins) {
      if (i - c >= 0 && value[i - c] < INF) {
        value[i] = min(value[i], value[i - c] + 1);
      }
    }
  }

  int result = value[x];

  if (result == INF) {
    cout << "-1";
  } else {
    cout << result;
  }
}