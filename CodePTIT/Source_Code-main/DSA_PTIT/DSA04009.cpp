#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
const ll MOD = 1e9 + 7;
ll n, k;
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
            {
                ll temp = (mtr1.a[i][k] * mtr2.a[k][j]) % MOD;
                res.a[i][j] = (res.a[i][j] + temp) % MOD;
            }
        }
    }
    return res;
}
Mat Power(Mat a, int p)
{
    if (p == 1)
        return a;
    Mat ans = Power(a, p / 2);
    if (p % 2)
        return ans * ans * a;
    return ans * ans;
}
void Solve()
{
    cin >> n >> k;
    Mat matrix;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
            cin >> matrix.a[i][j];
    }
    Mat ans = Power(matrix, k);
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
            cout << ans.a[i][j] << " \n"[j == n];
    }
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
