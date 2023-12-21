#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
const ll MOD = 1e9 + 7;
ll n, m;
struct Mat
{
    ll a[5][5];
};
Mat operator*(Mat mtr1, Mat mtr2)
{
    Mat res;
    memset(res.a, 0, sizeof(res.a));
    for (ll i = 1; i <= 3; i++)
    {
        for (ll j = 1; j <= 3; j++)
        {
            for (ll k = 1; k <= 3; k++)
            {
                ll temp = (mtr1.a[i][k] * mtr2.a[k][j]) % MOD;
                res.a[i][j] = (res.a[i][j] + temp) % MOD;
            }
        }
    }
    return res;
}
Mat Power(Mat a, ll p)
{
    if (p == 1)
        return a;
    Mat ans = Power(a, p / 2);
    if (p % 2)
        return ans * ans * a;
    return ans * ans;
}
int main()
{
    ll m;
    cin >> m;
    vector<ll> arr(m);
    for (auto &x : arr)
        cin >> x;
    Mat tmp;
    tmp.a[1][1] = 3;
    tmp.a[2][1] = 2;
    tmp.a[3][1] = 1;
    tmp.a[1][2] = tmp.a[1][3] = 0;
    tmp.a[2][2] = tmp.a[2][3] = 0;
    tmp.a[3][2] = tmp.a[3][3] = 0;
    Mat mid;
    mid.a[1][1] = 3, mid.a[1][2] = -2, mid.a[1][3] = 1;
    mid.a[2][1] = 1, mid.a[2][2] = 0, mid.a[2][3] = 0;
    mid.a[3][1] = 0, mid.a[3][2] = 1, mid.a[3][3] = 0;
    for (ll i = 0; i < m; i++)
    {
        if (arr[i] < 4)
            continue;
        Mat qans = Power(mid, arr[i] - 3);
        qans = qans * tmp;
        arr[i] = (qans.a[1][1] + MOD) % MOD;
    }
    for (auto x : arr)
        cout << x << " ";
    return 0;
}
