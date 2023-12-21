#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
void Solve()
{
    int n;
    cin >> n;
    vector<ll> a(n), dp(n);
    for (auto &x : a)
        cin >> x;
    dp[0] = a[0], dp[1] = max(a[0], a[1]);
    for (int i = 2; i < n; i++)
        dp[i] = max(dp[i - 1], dp[i - 2] + a[i]);
    cout << dp[n - 1] << "\n";
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
