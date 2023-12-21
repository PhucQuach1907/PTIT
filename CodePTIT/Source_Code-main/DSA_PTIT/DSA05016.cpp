#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<ll> dp(n + 5);
        dp[0] = 1;
        int idx = 1, two = 0, three = 0, five = 0;
        while (idx < n)
        {
            dp[idx] = min({dp[two] * 2, dp[three] * 3, dp[five] * 5});
            if (dp[idx] == dp[two] * 2)
                two++;
            else if (dp[idx] == dp[three] * 3)
                three++;
            else
                five++;
            if (dp[idx] == dp[idx - 1])
                continue;
            idx++;
        }
        cout << dp[n - 1] << "\n";
    }
    return 0;
}
