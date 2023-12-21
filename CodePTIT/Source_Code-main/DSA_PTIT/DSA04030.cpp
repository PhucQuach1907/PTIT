#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define ull unsigned long long
const ll MOD = 1e15 + 7;
struct Mat
{
    ll a[5][5];
};
ll Mul(ll a, ll b)
{
    ll res = 0LL;
    while (b)
    {
        if (b & 1)
            res = (res + a) % MOD;
        a = (a + a) % MOD;
        b >>= 1;
    }
    return res % MOD;
}
Mat operator*(Mat mtr1, Mat mtr2)
{
    Mat res;
    memset(res.a, 0, sizeof(res.a));
    for (ll i = 1; i <= 4; i++)
    {
        for (ll j = 1; j <= 4; j++)
        {
            for (ll k = 1; k <= 4; k++)
                res.a[i][j] = (res.a[i][j] + Mul(mtr1.a[i][k], mtr2.a[k][j])) % MOD;
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
Mat temp, x, ans;
int n;
int main()
{
    x.a[1][1] = x.a[1][2] = x.a[1][3] = x.a[1][4] = 1ll;
    x.a[2][2] = x.a[2][3] = x.a[2][4] = 1ll;
    x.a[3][2] = x.a[4][3] = 1ll;
    temp.a[1][1] = 6ll;
    temp.a[2][1] = 3ll;
    temp.a[3][1] = 2ll;
    temp.a[4][1] = 1ll;
    int t;
    cin >> t;
    while (t--)
    {
        cin >> n;
        if (n <= 3)
        {
            if (n == 0)
                cout << 0 << "\n";
            else if (n == 1)
                cout << 1 << "\n";
            else if (n == 2)
                cout << 3 << "\n";
            else if (n == 3)
                cout << 6 << "\n";
            continue;
        }
        ans = Power(x, n - 3) * temp;
        cout << ans.a[1][1] << "\n";
    }
    return 0;
}
