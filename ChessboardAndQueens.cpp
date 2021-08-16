#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;

size_t n = 8;
vector<bool> col(n, false);
vector<bool> diag1(2 * n, false);
vector<bool> diag2(2 * n, false);

void search(size_t y, ll& count, vector<string> board) {
  if (y == n) {
    count += 1;
  } else {
    for (size_t x = 0; x < n; x++) {
      if (!(col[x] || diag1[x + y] || diag2[x - y + n - 1] ||
            board[y][x] == '*')) {
        col[x] = diag1[x + y] = diag2[x - y + n - 1] = true;
        search(y + 1, count, board);
        col[x] = diag1[x + y] = diag2[x - y + n - 1] = false;
      }
    }
  }
}

void solve() {
  vector<string> board;
  for (size_t i = 0; i < n; i++) {
    string line;
    cin >> line;
    board.push_back(line);
  }

  ll count = 0;
  search(0, count, board);
  cout << count << "\n";
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}