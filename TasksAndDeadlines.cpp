#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

typedef long long ll;

int main() {
  int n;
  cin >> n;

  vector<pair<int, int>> dds;

  for (int i = 0; i < n; i++) {
    int a, d;
    cin >> a;
    cin >> d;
    dds.push_back({a, d});
  }

  sort(dds.begin(), dds.end());
  ll reward = 0;
  ll x = 0;

  for (int i = 0; i < n; i++) {
    pair<int, int> p = dds[i];
    int a, d;
    a = p.first;
    d = p.second;

    x += a;
    reward += d - x;
  }

  cout << reward;
}