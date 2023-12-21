#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
void Solve()
{
    string s;
    cin >> s;
    int n = s.size();
    ll ans = 0;
    vector<ll> dp(n);
    dp[0] = s[0] - '0';
    ans += dp[0];
    for (int i = 1; i < (int)s.size(); i++)
    {
        dp[i] = (i + 1) * (s[i] - '0') + 10 * dp[i - 1];
        ans += dp[i];
    }
    cout << ans << "\n";
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        Solve();
    }
    return 0;
}
/*1234
dp[1] = 1
dp[2] = 2 + 12
dp[3] = 3 + 23 + 123
dp[4] = 4 + 34 + 234 + 1234
      = 4 + 30 + 4 + 230 + 4 + 1230 + 4
      = 4 * 4 + 10 * (3 + 23 + 123)
=> dp[i] = i * s[i] + 10 * dp[i-1]*/
