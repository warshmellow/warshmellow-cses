#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <map>

using namespace std;

typedef long long ll;

ll f(ll n)
{

    ll MOD = 1000000000 + 7;
    map<ll, ll> mp;
    mp[0] = 0;
    mp[1] = 1;
    mp[2] = 2;
    mp[3] = 4;
    mp[4] = 8;
    mp[5] = 16;
    mp[6] = 32;

    if (0 <= n && n <= 6)
    {
        return mp[n];
    }

    ll currSum = 0;
    for (ll i = 1; i <= 6; i++)
    {
        currSum += mp[i];
    }

    if (n == 7)
    {
        return currSum;
    }

    mp[7] = currSum;
    for (long i = 8; i <= n; i++)
    {
        // process i; eventually we'll do n and return
        // get sum of mp[n - 1] to mp[n - 6]
        // store mp[n] = this sum
        // currSum is answer for 7
        // update for 8 by subtracting mp[1] = mp[8 - 7]
        ll lower = i - 7;
        currSum = (currSum % MOD + currSum % MOD - mp[lower]) % MOD;
        mp[i] = currSum;
    }

    ll result = mp[n];
    if (result < 0)
    {
        return result + MOD;
    }
    else
    {
        return result;
    }
    return 0;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    ll n;
    cin >> n;

    cout << f(n) << "\n";
}