#include <iostream>
#include <vector>

using namespace std;

typedef vector<int> vi;

vi g(int n) {
  vi result(n);
  for (int i = 1; i < n + 1; i++) {
    for (int j = i; j < n + 1; j += i) {
      result[j]++;
    }
  }
  return result;
}

int main() {
  int MAX_X = 1e6;

  int n;
  cin >> n;

  vi result = g(MAX_X + 1);

  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;

    cout << result[x] << "\n";
  }
}