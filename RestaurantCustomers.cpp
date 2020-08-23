#include <algorithm>
#include <iostream>
#include <map>
#include <vector>

using namespace std;

int g(vector<pair<int, int>> intervals) {
  int n = intervals.size();
  sort(intervals.begin(), intervals.end());
  map<int, int> by_start;
  map<int, int> by_end;

  vector<int> allt;

  for (int i = 0; i < n; i++) {
    pair<int, int> p = intervals[i];
    int start = p.first;
    int end = p.second;
    by_start[start] = end;
    by_end[end] = start;
    allt.push_back(start);
    allt.push_back(end);
  }

  sort(allt.begin(), allt.end());

  int count = 0;
  int max_count = 0;

  for (auto i : allt) {
    if (by_start.count(i))
      count++;
    else if (by_end.count(i))
      count--;

    max_count = max(max_count, count);
  }

  return max_count;
}

int main() {
  int n;
  cin >> n;

  vector<pair<int, int>> intervals;
  for (int i = 0; i < n; i++) {
    int arrival;
    int leaving;
    cin >> arrival;
    cin >> leaving;
    intervals.push_back({arrival, leaving});
  }

  cout << g(intervals) << "\n";
}