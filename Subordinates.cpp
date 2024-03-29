#include <algorithm>
#include <iostream>
#include <map>
#include <set>
#include <vector>

using namespace std;

typedef vector<int> vi;

const int max_n = 2e5;

// Adjacency list adj and sub counts need to be passed by reference via &
// subs includes self in the count. Strict subs is subs - 1
void dfs(vector<vi>& adj, vi& subs, int u) {
  subs[u] = 1;
  for (int v : adj[u]) {
    dfs(adj, subs, v);
    subs[u] += subs[v];
  }
}

int main() {
  vector<vi> adj(max_n + 1);

  // subs[i] = number of subordinates of i, including self
  vi subs(max_n + 1, 0);

  int n;
  cin >> n;

  for (int i = 2; i < n + 1; i++) {
    int p;
    cin >> p;
    adj[p].push_back(i);
  }

  dfs(adj, subs, 1);

  for (int i = 1; i < n + 1; i++) {
    int strict_subs = subs[i] - 1;
    cout << strict_subs << " ";
  }
}