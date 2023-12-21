#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
int n, m, k, a[505][505], dp[505][505];
void Factorization(vector<pair<int, int>> &div)
{
    for (int i = 1; i <= k; i++)
    {
        if (k % i == 0)
        {
            int l = i, r = k / i;
            if (l <= n && r <= m)
                div.push_back({l, r});
        }
    }
}
int Calc(int h, int w)
{
    int pref_col[n - h + 2][m + 1];
    memset(pref_col, 0, sizeof(pref_col));
    for (int j = 1; j <= m; j++)
    {
        for (int i = 1; i <= n - h + 1; i++)
            pref_col[i][j] = dp[i + h - 1][j] - dp[i - 1][j];
    }
    int pref_row[n - h + 2][m + 1];
    memset(pref_row, 0, sizeof(pref_row));
    for (int i = 1; i <= n - h + 1; i++)
    {
        for (int j = 1; j <= m; j++)
            pref_row[i][j] = pref_row[i][j - 1] + pref_col[i][j];
    }
    int ans = INT_MAX;
    for (int i = 1; i <= n - h + 1; i++)
    {
        for (int j = 1; j <= m - w + 1; j++)
            ans = min(ans, pref_row[i][j + w - 1] - pref_row[i][j - 1]);
    }
    return ans;
}
int main()
{
    cin >> n >> m >> k;
    for (int i = 1; i <= n; i++)
    {
        string s;
        cin >> s;
        for (int j = 0; j < s.size(); j++)
            a[i][j + 1] = s[j] - '0';
    }
    vector<pair<int, int>> div;
    Factorization(div);
    if (div.size() == 0)
    {
        cout << -1;
        return 0;
    }
    memset(dp, 0, sizeof(dp));
    for (int j = 1; j <= m; j++)
    {
        for (int i = 1; i <= n; i++)
            dp[i][j] = dp[i - 1][j] + a[i][j];
    }
    int res = INT_MAX;
    for (int i = 0; i < div.size(); i++)
        res = min(res, Calc(div[i].first, div[i].second));
    cout << res;
    return 0;
}