#include <algorithm>
#include <iostream>
#include <map>
#include <set>
#include <vector>

using namespace std;

typedef vector<int> vi;

const int max_n = 2e5;

// adjacency list adj and sub counts need to be passed by reference via &
void dfs(vector<vi>& adj, vi& subs, int u) {
  for (int v : adj[u]) {
    dfs(adj, subs, v);
    subs[u] += subs[v];
  }
}

int main() {
  vector<vi> adj(max_n + 1);
  vi subs(max_n + 1, 1);

  int n;
  cin >> n;

  for (int i = 2; i < n + 1; i++) {
    int p;
    cin >> p;
    adj[p].push_back(i);
  }

  dfs(adj, subs, 1);

  for (int i = 1; i < n + 1; i++) {
    cout << subs[i] - 1 << " ";
  }
}