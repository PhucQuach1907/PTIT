#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
void Solve()
{
    int n, S;
    cin >> n >> S;
    vector<bool> dp(S + 1, false);
    dp[0] = 1;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        for (int j = S; j >= x; j--)
        {
            if (j >= x && dp[j - x])
                dp[j] = 1;
        }
    }
    cout << (dp[S] ? "YES\n" : "NO\n");
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
