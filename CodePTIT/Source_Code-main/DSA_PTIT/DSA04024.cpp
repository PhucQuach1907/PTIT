#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
const ll MOD = 1e9 + 7;
ll n;
struct Mat
{
    ll a[15][15];
};
Mat operator*(Mat mtr1, Mat mtr2)
{
    Mat res;
    memset(res.a, 0, sizeof(res.a));
    for (ll i = 1; i <= n; i++)
    {
        for (ll j = 1; j <= n; j++)
        {
            for (ll k = 1; k <= n; k++)
                res.a[i][j] = (res.a[i][j] + (mtr1.a[i][k] * mtr2.a[k][j]) % MOD) % MOD;
        }
    }
    return res;
}
Mat Power(Mat a, int x)
{
    if (x == 1)
        return a;
    Mat ans = Power(a, x / 2);
    if (x % 2)
        return ans * ans * a;
    return ans * ans;
}
void Solve()
{
    ll k;
    cin >> n >> k;
    Mat mat;
    for (ll i = 1; i <= n; i++)
    {
        for (ll j = 1; j <= n; j++)
            cin >> mat.a[i][j];
    }
    Mat ans = Power(mat, k);
    ll res = 0;
    for (ll i = 1; i <= n; i++)
        res = (res + ans.a[i][n]) % MOD;
    cout << res << "\n";
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
