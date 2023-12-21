#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
struct Obj
{
    int w, v;
};
void Solve()
{
    int n, M;
    cin >> n >> M;
    vector<Obj> a(n);
    for (auto &x : a)
        cin >> x.w;
    for (auto &x : a)
        cin >> x.v;
    vector<vector<int>> dp(n, vector<int>(M + 1, 0));
    dp[0][a[0].w] = a[0].v;
    for (int i = 1; i < n; i++)
    {
        for (int j = 1; j <= M; j++)
        {
            dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            if (j >= a[i].w)
                dp[i][j] = max(dp[i][j], dp[i - 1][j - a[i].w] + a[i].v);
        }
    }
    cout << dp[n - 1][M] << "\n";
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
