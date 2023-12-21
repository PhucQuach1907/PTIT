#include <bits/stdc++.h>
using namespace std;
#define ui64 unsigned long long
#define ll long long
ll a[305][305], ker[4][4];
ll Merge(ll start_row, ll end_row, ll start_col, ll end_col)
{
    ll ans = 0, p = 1;
    for (ll i = start_row; i <= end_row; i++)
    {
        ll q = 1;
        for (ll j = start_col; j <= end_col; j++)
            ans += (a[i][j] * ker[p][q++]);
        p++;
    }
    return ans;
}
int main()
{
    ll t;
    cin >> t;
    while (t--)
    {
        ll n, m;
        cin >> n >> m;
        for (ll i = 1; i <= n; i++)
        {
            for (ll j = 1; j <= m; j++)
                cin >> a[i][j];
        }
        for (ll i = 1; i <= 3; i++)
        {
            for (ll j = 1; j <= 3; j++)
                cin >> ker[i][j];
        }
        ll res = 0;
        for (ll i = 1; i <= n - 2; i++)
        {
            for (ll j = 1; j <= m - 2; j++)
                res += Merge(i, i + 2, j, j + 2);
        }
        cout << res << "\n";
    }
    return 0;
}