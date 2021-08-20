#include <algorithm>
#include <iostream>
#include <vector>

typedef long long ll;

using namespace std;

vector<size_t> josh(vector<size_t> &person, size_t k) {
  vector<size_t> result;
  size_t index = 0;
  while (person.size() > 1) {
    index = (index + k) % person.size();
    result.push_back(person[index]);
    person.erase(person.begin() + index);
  }
  result.push_back(person[0]);
  return result;
}

void solve() {
  size_t n;
  cin >> n;

  size_t k = 2;
  k--;

  vector<size_t> person;
  for (size_t i = 1; i < n + 1; i++) {
    person.push_back(i);
  }

  for (size_t x : josh(person, k)) {
    cout << x << " ";
  }
  cout << "\n";
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}