#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
int main()
{
    int n, k;
    cin >> n >> k;
    vector<int> a(n), dp(n);
    for (auto &x : a)
        cin >> x;
    dp[0] = a[0];
    int res = dp[0];
    for (int i = 1; i < n; i++)
    {
        dp[i] = (i < k ? a[i] : INT_MIN);
        for (int j = i - 1; j >= max(0, i - k); j--)
            dp[i] = max(dp[i], dp[j] + a[i]);
        res = max(res, dp[i]);
    }
    cout << res;
    return 0;
}
