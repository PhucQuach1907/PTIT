#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
struct Mat
{
    ll a[15][15];
    ll n;
};
Mat Make_Matrix(Mat mat, ll col)
{
    Mat ans;
    ans.n = mat.n - 1;
    for (ll i = 2; i <= mat.n; i++)
    {
        ll k = 1;
        for (ll j = 1; j <= mat.n; j++)
        {
            if (j != col)
                ans.a[i - 1][k++] = mat.a[i][j];
        }
    }
    return ans;
}
ll Determinant(Mat v)
{
    if (v.n == 2)
        return (v.a[1][1] * v.a[2][2] - v.a[1][2] * v.a[2][1]);
    ll ans = 0;
    for (ll c = 1; c <= v.n; c++)
    {
        Mat tmp = Make_Matrix(v, c);
        ans += (Determinant(tmp) * v.a[1][c] * (c & 1LL ? 1LL : -1LL));
    }
    return ans;
}
int main()
{
    Mat m;
    cin >> m.n;
    for (ll i = 1; i <= m.n; i++)
    {
        for (ll j = 1; j <= m.n; j++)
            cin >> m.a[i][j];
    }
    ll sum = 0;
    for (ll i = 1; i <= m.n; i++)
        sum += m.a[i][i];
    cout << sum << "\n" << Determinant(m);
    return 0;
}
