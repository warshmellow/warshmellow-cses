#include <algorithm>
#include <iostream>
#include <map>
#include <set>
#include <vector>

using namespace std;

typedef long long ll;
typedef vector<int> vi;

ll g(vi a) {
  const int max_n = 2e5;
  const int n = a.size();

  vi freq(max_n);
  ll cnt = 0;
  int pre = 0;

  freq[0] = 1;

  for (int i = 0; i < n; i++) {
    int ai = a[i];
    pre = ((pre + ai) % n + n) % n;
    cnt += freq[pre];
    freq[pre]++;
  }
  return cnt;
}

int main() {
  int n;
  cin >> n;

  vi a;
  for (int i = 0; i < n; i++) {
    int ai;
    cin >> ai;
    a.push_back(ai);
  }

  cout << g(a) << "\n";
}