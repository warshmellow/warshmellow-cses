#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool is_beautiful(vector<int> permutation)
{
    int count = permutation.size();
    for (int i = 1; i < count; i++)
    {
        if (abs(permutation[i - 1] - permutation[i]) == 1)
        {
            return false;
        }
    }
    return true;
}

vector<int> f(int n)
{
    if (n == 4)
    {
        return {2, 4, 1, 3};
    }

    vector<int> odds;
    vector<int> evens;

    for (int i = 1; i <= n; i++)
    {
        if (i % 2 == 0)
        {
            evens.push_back(i);
        }
        else
        {
            odds.push_back(i);
        }
    }
    odds.insert(odds.end(), evens.begin(), evens.end());
    if (is_beautiful(odds))
    {
        return odds;
    }
    else
    {
        return {};
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    vector<int> result = f(n);

    if (result.size() == 0)
    {
        cout << "NO SOLUTION\n";
    }
    else
    {
        int count = result.size();
        for (int i = 0; i < count; i++)
        {
            cout << result[i] << " ";
        }
        cout << "\n";
    }
}