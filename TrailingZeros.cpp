#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>

using namespace std;

typedef long long ll;

int f(ll n)
{
    int count = 0;
    for (int i = 5; n / i >= 1; i *= 5)
    {
        count += n / i;
    }
    return count;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    cout << f(n) << "\n";
}