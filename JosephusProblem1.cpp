#include <algorithm>
#include <iostream>
#include <vector>

typedef long long ll;

using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

#define ordered_set                            \
  tree<int, null_type, less<int>, rb_tree_tag, \
       tree_order_statistics_node_update>

vector<int> josh(ordered_set &person, size_t k) {
  vector<int> result;
  size_t index = 0;
  while (person.size() > 1) {
    index = (index + k) % person.size();
    result.push_back(*person.find_by_order(index));
    person.erase(*person.find_by_order(index));
  }
  result.push_back(*person.begin());
  return result;
}

void solve() {
  size_t n;
  cin >> n;

  size_t k = 2;
  k--;

  ordered_set person;
  for (int i = 1; i < n + 1; i++) {
    person.insert(i);
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