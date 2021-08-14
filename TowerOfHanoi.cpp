#include <iostream>
#include <vector>

using namespace std;

vector<pair<int, int>> h(int n, int src, int dst, int tmp) {
  if (n > 0) {
    vector<pair<int, int>> move1 = h(n - 1, src, tmp, dst);

    pair<int, int> p{src, dst};
    vector<pair<int, int>> move_largest = {p};

    vector<pair<int, int>> move2 = h(n - 1, tmp, dst, src);

    vector<pair<int, int>> result;
    result.insert(result.end(), move1.begin(), move1.end());
    result.insert(result.end(), move_largest.begin(), move_largest.end());
    result.insert(result.end(), move2.begin(), move2.end());
    return result;
  } else {
    return vector<pair<int, int>>{};
  }
}

void solve() {
  int n;
  cin >> n;

  vector<pair<int, int>> result = h(n, 1, 3, 2);

  cout << result.size() << "\n";

  for (size_t i = 0; i < result.size(); i++) {
    pair<int, int> p = result[i];
    cout << p.first << " " << p.second << "\n";
  }
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}