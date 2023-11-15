#include <iostream>
#include <vector>

using namespace std;

typedef vector<int> vi;

int main() {
  int n;
  cin >> n;

  /* Note that indices are 1-based!
    nearest_smaller_indices[0] = 0;
    nearest_smaller_indices[1] = 0;
    nearest_smaller_indices[2] =  1 if x[1] < x[2] else 0
    ...
    nearest_smaller_indices[i] = j < i where x[j] < x[i]
    or 0 if j not exists

    What is nearest_smaller_indices[i - 1]?
    j < i - 1 where x[j] < x[i - 1]. We resort to this if
    x[i - 1] >= x[i]. We need x[j] < x[i], so we can skip
    all those between nearest_smaller_indices[i - 1], as
    the values are >= x[i - 1]
  */

  vi x(n + 1, 0);
  vi nearest_smaller_indices(n + 1, 0);

  for (int i = 1; i < n + 1; i++) {
    int xi;
    cin >> xi;
    x[i] = xi;
  }

  for (int i = 1; i < n + 1; i++) {
    int candidate = i - 1;
    while (x[candidate] >= x[i]) {
      candidate = nearest_smaller_indices[candidate];
    }
    nearest_smaller_indices[i] = candidate;
  }

  for (int i = 1; i < n + 1; i++) {
    cout << nearest_smaller_indices[i] << " ";
  }
}
