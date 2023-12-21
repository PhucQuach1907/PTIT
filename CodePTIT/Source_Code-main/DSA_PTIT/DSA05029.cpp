#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
int Count(string s)
{
    if (s[0] == '0')
        return 0;
    int len = s.size();
    s = "-" + s;
    vector<int> dp(len + 1, 0);
    dp[0] = dp[1] = 1;
    for (int i = 2; i <= len; i++)
    {
        if (s[i] > '0')
            dp[i] = dp[i - 1];
        if (s[i - 1] == '1' || (s[i - 1] == '2' && s[i] < '7'))
            dp[i] += dp[i - 2];
    }
    return dp[len];
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string s;
        cin >> s;
        cout << Count(s) << "\n";
    }
    return 0;
}
