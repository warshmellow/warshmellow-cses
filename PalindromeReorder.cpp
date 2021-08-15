#include <math.h>

#include <algorithm>
#include <deque>
#include <iostream>
#include <map>
#include <set>
#include <vector>

using namespace std;

typedef long long ll;
typedef vector<ll> vll;
typedef set<ll> sll;
typedef map<char, ll> mcll;
typedef vector<char> vc;
typedef pair<char, ll> pcll;
typedef deque<char> dc;

mcll get_counts(string s) {
  mcll result;
  for (char c : s) {
    if (result.count(c) > 0)
      result[c]++;
    else
      result[c] = 1;
  }
  return result;
}

vc get_odd_strings(mcll mp) {
  vc result;
  for (pcll p : mp) {
    if (p.second % 2 != 0) {
      result.push_back(p.first);
    }
  }
  return result;
}

string f(string s) {
  mcll mp = get_counts(s);
  vc odd_strings = get_odd_strings(mp);

  if (odd_strings.size() > 1) return "";

  dc result_list;

  if (odd_strings.size() == 1) {
    char odd_string = odd_strings[0];
    ll cnt = mp[odd_string];
    for (ll i = 0; i < cnt; i++) {
      result_list.push_back(odd_string);
    }
  }

  set<char> odd_strings_set(odd_strings.begin(), odd_strings.end());

  for (pcll p : mp) {
    char ch = p.first;
    ll cnt = p.second;
    if (odd_strings_set.count(ch) > 0) continue;

    ll half = cnt / 2;

    for (ll i = 0; i < half; i++) {
      result_list.push_front(ch);
      result_list.push_back(ch);
    }
  }

  string result = "";
  for (char c : result_list) {
    result += c;
  }
  return result;
}

void solve() {
  string s;
  cin >> s;

  string result = f(s);
  if (result != "")
    cout << result << "\n";
  else
    cout << "NO SOLUTION\n";
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return (0);
}