#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
int main()
{
    vector<vector<int>> dp(901, vector<int>(8101, 105));
    dp[0][0] = 0;
    for (int i = 1; i <= 900; i++)
    {
        for (int j = 1; j <= 8100; j++)
        {
            for (int dig = 1; dig < 10; dig++)
            {
                if (i >= dig && j >= dig * dig)
                {
                    if (dp[i - dig][j - dig * dig] != 105)
                        dp[i][j] = min(dp[i][j], dp[i - dig][j - dig * dig] + 1);
                }
            }
        }
    }
    int t;
    cin >> t;
    while (t--)
    {
        int a, b;
        cin >> a >> b;
        if (a > 900 || b > 8101 || dp[a][b] > 100)
            cout << -1 << "\n";
        else
        {
            while (a > 0 && b > 0)
            {
                for (int i = 1; i < 10; i++)
                {
                    if (a >= i && b >= i * i && dp[a][b] == dp[a - i][b - i * i] + 1)
                    {
                        cout << i;
                        a -= i;
                        b -= i * i;
                        break;
                    }
                }
            }
            cout << "\n";
        }
    }
    return 0;
}
