#include <math.h>

#include <algorithm>
#include <iostream>
#include <map>
#include <set>
#include <vector>

using namespace std;

typedef long long ll;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  ll n;
  cin >> n;

  ll x;
  set<ll> nums;
  while (cin >> x) {
    nums.insert(x);
  }

  cout << nums.size() << "\n";
}