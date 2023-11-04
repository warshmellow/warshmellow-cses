#include <iostream>
#include <vector>

using namespace std;

typedef vector<bool> vb;
typedef vector<vb> vvb;
typedef vector<int> vi;

vvb visited;

// Finds connected components of x, y, filling in x, y as wall once visited
void dfs(int x, int y, int n, int m) {
  visited[x][y] = true;

  // down, up, right, left
  vi h = {1, -1, 0, 0};
  vi v = {0, 0, 1, -1};

  for (int i = 0; i < 4; i++) {
    int dx = x + h[i];
    int dy = y + v[i];

    if (0 <= dx && dx < n && 0 <= dy && dy < m && !visited[dx][dy]) {
      dfs(dx, dy, n, m);
    }
  }
}

int main() {
  int n, m;
  cin >> n;
  cin >> m;

  for (int i = 0; i < n; i++) {
    string line;
    cin >> line;

    vb row;
    for (int j = 0; j < m; j++) {
      row.push_back(line[j] == '#');
    }

    visited.push_back(row);
  }

  int count = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (!visited[i][j]) {
        // Find connected component containing floor tile i, j
        dfs(i, j, n, m);
        count++;
      }
    }
  }

  cout << count << "\n";
}