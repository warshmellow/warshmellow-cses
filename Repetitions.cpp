#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int f(string s)
{
    int i = 0;
    int maxLen = 1;
    int currLen = 1;

    for (int j = 1; i < s.length(); j++)
    {
        if (s[i] == s[j])
        {
            currLen++;
        }
        else
        {
            maxLen = max(maxLen, currLen);
            i = j;
            currLen = 1;
        }
    }

    return maxLen;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    string s;
    cin >> s;

    cout << f(s) << "\n";
}