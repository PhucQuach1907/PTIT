#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
int main()
{
    int n;
    cin >> n;
    vector<ll> a(n), dp(n);
    for (auto &x : a)
        cin >> x;
    dp[0] = 0;
    dp[1] = abs(a[1] - a[0]);
    for (int i = 2; i < n; i++)
    {
        ll m1 = dp[i - 1] + abs(a[i] - a[i - 1]);
        ll m2 = dp[i - 2] + abs(a[i] - a[i - 2]);
        dp[i] = min(m1, m2);
    }
    cout << dp[n - 1];
    return 0;
}
