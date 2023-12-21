#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
struct Obj
{
    ll w, v;
};
int main()
{
    ll n, M;
    cin >> n >> M;
    vector<Obj> a(n);
    for (auto &x : a)
        cin >> x.w >> x.v;
    ll dp[n][M + 1], ans = 0;
    memset(dp, 0, sizeof(dp));
    dp[0][a[0].w] = a[0].v;
    for (ll i = 1; i < n; i++)
    {
        for (ll j = 1; j <= M; j++)
        {
            dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            if (j >= a[i].w)
                dp[i][j] = max(dp[i][j], dp[i - 1][j - a[i].w] + a[i].v);
        }
    }
    cout << dp[n - 1][M];
    return 0;
}
