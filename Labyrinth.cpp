#include <iostream>
#include <queue>
#include <vector>

using namespace std;

typedef pair<int, int> pt;
typedef pair<pt, string> pt_path;
typedef vector<bool> vb;
typedef vector<vb> vvb;
typedef vector<int> vi;

vvb visited;
int n, m;
string shortest_path;

bool bfs(pt start_pt, pt end_pt) {
  pt_path start_pt_path(start_pt, "");

  queue<pt_path> q;
  q.push(start_pt_path);

  // down, up, right, left
  vi h = {1, -1, 0, 0};
  vi v = {0, 0, 1, -1};
  vector<string> d = {"D", "U", "R", "L"};

  while (!q.empty()) {
    pt_path curr = q.front();
    q.pop();

    pt curr_pt = curr.first;
    string curr_path = curr.second;

    int x = curr_pt.first;
    int y = curr_pt.second;

    if (curr_pt == end_pt) {
      shortest_path = curr_path;
      return true;
    }

    for (int i = 0; i < 4; i++) {
      int dx = x + h[i];
      int dy = y + v[i];

      if (0 <= dx && dx < n && 0 <= dy && dy < m && !visited[dx][dy]) {
        visited[dx][dy] = true;

        pt next_pt(dx, dy);
        curr_path.append(d[i]);
        pt_path next_pt_path(next_pt, curr_path);
        curr_path.pop_back();

        q.push(next_pt_path);
      }
    }
  }

  return false;
}

int main() {
  cin >> n;
  cin >> m;

  pt start_pt;
  pt end_pt;

  for (int i = 0; i < n; i++) {
    string line;
    cin >> line;

    vb row;
    for (int j = 0; j < m; j++) {
      if (line[j] == 'A') {
        start_pt.first = i;
        start_pt.second = j;
        row.push_back(true);
      } else if (line[j] == 'B') {
        end_pt.first = i;
        end_pt.second = j;
        row.push_back(false);
      } else {
        row.push_back(line[j] == '#');
      }
    }

    visited.push_back(row);
  }

  bool path_found = bfs(start_pt, end_pt);

  if (path_found) {
    cout << "YES"
         << "\n";
    cout << shortest_path.length() << "\n";
    cout << shortest_path << "\n";

  } else {
    cout << "NO"
         << "\n";
  }
}