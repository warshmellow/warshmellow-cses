#include <iostream>
#include <queue>
#include <vector>

using namespace std;

typedef long long ll;
const int max_n = 2e5 + 1;

vector<int> G[max_n];
int a, b, c;
int farthest, max_dist;
int dist[max_n];

void dfs(int s, int e) {
  dist[s] = 1 + dist[e];

  if (max_dist <= dist[s]) {
    farthest = s;
    max_dist = dist[s];
  }

  for (auto u : G[s]) {
    if (u != e) dfs(u, s);
  }
}

int main() {
  int n;
  cin >> n;

  if (n == 1) {
    cout << 0;
    return 0;
  } else if (n == 2) {
    cout << 1;
    return 0;
  }

  for (int i = 0; i < n; i++) {
    int a, b;
    cin >> a;
    cin >> b;
    G[a].push_back(b);
    G[b].push_back(a);
  }

  dist[0] = -1;
  dfs(1, 0);
  b = farthest;

  farthest = 0;
  for (int i = 0; i < max_n; i++) {
    dist[i] = 0;
  }
  dist[0] = -1;
  dfs(b, 0);
  c = farthest;

  cout << dist[c];
}