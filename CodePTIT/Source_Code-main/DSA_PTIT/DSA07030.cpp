#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
int Calc(int n, vector<int> a)
{
    stack<int> stk;
    vector<int> l(n), r(n);
    for (int i = 0; i < n; i++)
    {
        if (stk.empty())
        {
            stk.push(i);
            continue;
        }
        while (!stk.empty() && a[i] < a[stk.top()])
        {
            r[stk.top()] = i;
            stk.pop();
        }
        stk.push(i);
    }
    while (!stk.empty())
    {
        r[stk.top()] = n;
        stk.pop();
    }
    for (int i = n - 1; i >= 0; i--)
    {
        if (stk.empty())
        {
            stk.push(i);
            continue;
        }
        while (!stk.empty() && a[i] < a[stk.top()])
        {
            l[stk.top()] = i;
            stk.pop();
        }
        stk.push(i);
    }
    while (!stk.empty())
    {
        l[stk.top()] = -1;
        stk.pop();
    }
    int res = -1;
    for (int i = 0; i < n; i++)
        res = max(res, a[i] * (r[i] - l[i] - 1));
    return res;
}
void Solve()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> a(n, vector<int>(m)), dp(n, vector<int>(m));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
            cin >> a[i][j];
    }
    dp[0] = a[0];
    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < m; j++)
            dp[i][j] = (a[i][j] == 0 ? 0 : dp[i - 1][j] + 1);
    }
    int ans = -1;
    for (int i = 0; i < n; i++)
        ans = max(ans, Calc(m, dp[i]));
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
