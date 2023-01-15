#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;
typedef vector<ll> vll;
typedef vector<vll> mat;

mat mult(mat A, mat B, ll m) {
  mat C{{0, 0}, {0, 0}};

  for (int i = 0; i < 2; i++) {
    for (int j = 0; j < 2; j++) {
      for (int k = 0; k < 2; k++) {
        C[i][j] += (A[i][k] * B[k][j]) % m;
        C[i][j] = C[i][j] % m;
      }
    }
  }
  return C;
}

mat modpow(mat x, ll n, ll m) {
  if (n == 0) {
    mat vect{{1, 0}, {0, 1}};
    return vect;
  }

  mat u = modpow(x, n / 2, m);

  u = mult(u, u, m);

  if (n % 2 == 1) u = mult(u, x, m);

  return u;
}

int main() {
  ll MOD = 1000000000 + 7;

  mat m;

  ll n;
  cin >> n;

  mat X{{0, 1}, {1, 1}};

  mat result = modpow(X, n, MOD);
  ll num = result[0][1];

  cout << num;
}