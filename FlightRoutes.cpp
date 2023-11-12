#include <iostream>
#include <queue>
#include <vector>

using namespace std;

typedef long long ll;
typedef pair<int, ll> edge;  // tail, price
typedef pair<ll, int> node;  // price, city
const int max_n = 2e5 + 1;

int seen[max_n];
// G[head] = [(tail, price)]
vector<edge> G[max_n];
// node is (price, city), priority queue is a min heap due to
// "greater<node>"
priority_queue<node, vector<node>, greater<node>> Q;

int main() {
  int n, m, k;

  cin >> n;
  cin >> m;
  cin >> k;

  for (int i = 0; i < m; i++) {
    int a, b, c;
    cin >> a;
    cin >> b;
    cin >> c;

    edge e(b, c);

    G[a].push_back(e);
  }

  Q.push({0, 1});  // 1 to 1 has 0 price

  while (!Q.empty()) {
    node curr_node = Q.top();     // min price from 1
    ll price = curr_node.first;   // price
    int curr = curr_node.second;  // current city
    Q.pop();

    seen[curr]++;  // inc times seen current city

    if (curr == n && seen[curr] == k) {
      cout << price << " ";
      return 0;
    } else if (curr == n) {
      cout << price << " ";
    }

    if ((curr == n && seen[curr] < k) || seen[curr] <= k) {
      for (edge e : G[curr]) {
        int tail = e.first;
        ll e_price = e.second;
        Q.push({price + e_price, tail});
      }
    }
  }
}