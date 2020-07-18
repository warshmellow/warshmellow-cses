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

ll f(vll nums)
{
    sll s;
    for (auto num : nums)
    {
        s.insert(num);
    }
    return s.size();
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    ll n;
    cin >> n;

    ll x;
    vll nums;
    while (cin >> x)
    {
        nums.push_back(x);
    }

    cout << f(nums) << "\n";
}