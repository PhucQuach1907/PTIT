#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define ull unsigned long long
const ll MOD = 1e9 + 7;
struct Mat
{
    ll a[3][3];
};
Mat operator*(Mat mtr1, Mat mtr2)
{
    Mat res;
    memset(res.a, 0, sizeof(res.a));
    for (ll i = 1; i <= 2; i++)
    {
        for (ll j = 1; j <= 2; j++)
        {
            for (ll k = 1; k <= 2; k++)
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
    ll n;
    cin >> n;
    n--;
    Mat matrix;
    for (int i = 1; i <= 2; i++)
    {
        for (int j = 1; j <= 2; j++)
            matrix.a[i][j] = 1;
    }
    matrix.a[2][2] = 0;
    cout << Power(matrix, n).a[1][1] << "\n";
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
