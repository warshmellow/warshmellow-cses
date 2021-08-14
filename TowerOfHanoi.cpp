#include <iostream>
#include <vector>

using namespace std;

typedef pair<int, int> pi;

vector<pi> h(int n, int src, int dst, int tmp) {
  if (n > 0) {
    vector<pi> move1 = h(n - 1, src, tmp, dst);
    pi p = make_pair(src, dst);
    vector<pi> move2 = h(n - 1, tmp, dst, src);

    move1.push_back(p);
    move1.insert(move1.end(), move2.begin(), move2.end());
    return move1;
  } else {
    return vector<pi>{};
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