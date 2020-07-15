#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>

using namespace std;

typedef long long ll;

int f(ll n, ll k)
{
    int count = 0;
    for (int i = k; n / i >= 1; i *= k)
    {
        count += n / i;
    }
    return count;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    ll n;
    cin >> n;

    cout << min(f(n, 5), f(n, 2)) << "\n";
}