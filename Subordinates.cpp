#include <algorithm>
#include <iostream>
#include <map>
#include <set>
#include <vector>

using namespace std;

typedef vector<int> vi;

const int max_n = 2e5;

vi sz(max_n + 1);
vector<vi> G(max_n + 1);

void dfs(int u) {
  sz[u] = 1;
  for (int v : G[u]) {
    dfs(v);
    sz[u] += sz[v];
  }
}

int main() {
  int n;
  cin >> n;

  for (int i = 2; i < n + 1; i++) {
    int p;
    cin >> p;
    G[p].push_back(i);
  }

  dfs(1);

  for (int i = 1; i < n + 1; i++) {
    cout << sz[i] - 1 << " ";
  }
}