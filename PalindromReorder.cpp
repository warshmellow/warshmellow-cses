#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <map>
#include <set>

using namespace std;

typedef long long ll;
typedef vector<ll> vll;
typedef set<ll> sll;

map<char, ll> get_counts(string s)
{
    map<char, ll> mp;
    for (auto c : s)
    {
        if (mp.count(c))
        {
            mp[c]++;
        }
        else
        {
            mp[c] = 1;
        }
    }
    return mp;
}

bool can_mk_palindrome(string s)
{
    ll numOdd = 0;
    map<char, ll> ctr = get_counts(s);
    for (auto x : ctr)
    {
        ll cnt = x.second;
        if (cnt % 2 == 1)
        {
            numOdd++;
        }
    }
    return numOdd <= 1;
}

vector<string> f(string s)
{
    vector<string> result;
    if (!can_mk_palindrome(s))
    {
        return result;
    }

    map<char, ll> ctr = get_counts(s);
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    string s;
    scanf("%s", &s);

    string result = f(s);

    if (!result)
    {
        cout << "NO SOLUTION\n";
    }

    cout << result << "\n";
}