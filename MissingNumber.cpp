#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int f(vector<int> nums)
{
    int count = nums.size();
    sort(nums.begin(), nums.end());
    for (int i = 0; i < count; i++)
    {
        int j = i + 1;
        if (j != nums[i])
        {
            return j;
        }
    }
    return count + 1;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    vector<int> nums;

    for (int i = 0; i < n - 1; i++)
    {
        int x;
        cin >> x;
        nums.push_back(x);
    }

    cout << f(nums) << "\n";
}