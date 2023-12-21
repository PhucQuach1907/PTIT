#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
struct Obj
{
    double w, v;
};
bool cmp(Obj a, Obj b)
{
    double r1 = a.v * 1.0 / a.w, r2 = b.v * 1.0 / b.w;
    return (r1 > r2);
}
void Solve()
{
    int n;
    double W;
    cin >> n >> W;
    vector<Obj> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i].v >> a[i].w;
    sort(a.begin(), a.end(), cmp);
    double res = 0;
    int i = 0;
    while (W >= a[i].w && i < n)
    {
        res += a[i].v;
        W -= a[i].w;
        i++;
    }
    res += (i < n ? W * a[i].v * 1.0 / a[i].w : 0);
    cout << fixed << setprecision(2) << res << "\n";
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
