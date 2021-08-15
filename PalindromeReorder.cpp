#include <math.h>

#include <algorithm>
#include <deque>
#include <iostream>
#include <map>
#include <set>
#include <vector>

using namespace std;

typedef long long ll;

map<char, ll> get_counts(string s) {
  map<char, ll> result;
  for (char c : s) {
    result[c]++;
  }
  return result;
}

vector<char> get_odd_strings(map<char, ll> mp) {
  vector<char> result;
  for (pair<char, ll> p : mp) {
    if (p.second % 2 != 0) {
      result.push_back(p.first);
    }
  }
  return result;
}

string f(string s) {
  map<char, ll> mp = get_counts(s);
  vector<char> odd_strings = get_odd_strings(mp);

  if (odd_strings.size() > 1) return "";

  deque<char> result_list;

  if (odd_strings.size() == 1) {
    char odd_string = odd_strings[0];
    ll cnt = mp[odd_string];
    for (ll i = 0; i < cnt; i++) {
      result_list.push_back(odd_string);
    }
  }

  set<char> odd_strings_set(odd_strings.begin(), odd_strings.end());

  for (pair<char, ll> p : mp) {
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