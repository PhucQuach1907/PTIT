#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, L;
    cin >> n >> L;
    vector<int> pref(n + 1);
    pref[0] = 0;
    for (int i = 1; i <= n; i++)
    {
        cin >> pref[i];
        pref[i] += pref[i - 1];
    }
    vector<int> dp(n + 1, INT_MAX);
    dp[0] = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = i; j > 0 && pref[i] - pref[j - 1] <= L; j--)
            dp[i] = min(dp[i], max(dp[j - 1], L - (pref[i] - pref[j - 1])));
    }
    cout << dp[n];
    return 0;
}
