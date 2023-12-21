#include <bits/stdc++.h>
using namespace std;
#define ui64 unsigned long long
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<long long> a(n), dp(n);
        for (auto &c : a)
            cin >> c;
        dp[n - 1] = a[n - 1], dp[n - 2] = max(a[n - 1], a[n - 2]);
        for (int i = n - 3; i >= 0; i--)
            dp[i] = max(dp[i + 2] + a[i], dp[i + 1]);
        cout << dp[0] << "\n";
    }
    return 0;
}