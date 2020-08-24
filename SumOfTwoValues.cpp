#include <algorithm>
#include <iostream>
#include <map>
#include <vector>

using namespace std;

pair<int, int> g(vector<int> a, int x) {
  int n = a.size();

  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++) {
      if (a[i] + a[j] == x) {
        return {i + 1, j + 1};
      }
    }
  }
  return {-1, -1};
}

int main() {
  int n;
  cin >> n;
  int x;
  cin >> x;

  vector<int> a;
  for (int i = 0; i < n; i++) {
    int y;
    cin >> y;
    a.push_back(y);
  }

  pair<int, int> result = g(a, x);

  if (result.first == -1) {
    cout << "IMPOSSIBLE"
         << "\n";
  } else {
    cout << result.first << " " << result.second << "\n";
  }
}