#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int f(string s) {
  int i = 0;
  int maxLen = 1;
  int currLen = 1;

  for (int j = 1; j < s.length(); j++) {
    if (s[i] == s[j]) {
      currLen++;
    } else {
      maxLen = max(maxLen, currLen);
      i = j;
      currLen = 1;
    }
  }
  maxLen = max(maxLen, currLen);
  return maxLen;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  string s;
  cin >> s;

  cout << f(s) << "\n";
}