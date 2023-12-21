#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
int main()
{
    vector<int> dp(10005, INT_MAX);
    dp[0] = 0;
    for (int i = 1; i <= 10000; i++)
    {
        for (int j = 1; j <= sqrt(i); j++)
            dp[i] = min(dp[i], dp[i - j * j] + 1);
    }
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        cout << dp[n] << "\n";
    }
    return 0;
}
