#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
struct Bag
{
    ll w, v;
};
Bag a[105];
ll n, W, res = -1;
bool cmp(Bag a, Bag b)
{
    return (float)a.v / a.w > (float)b.v / b.w;
}
void Try(ll index, ll cur_w, ll cur_v)
{
    int mx = cur_w / a[index].w;
    for (int i = min(1, mx); i >= 0; i--)
    {
        cur_v += (a[index].v * i);
        cur_w -= (a[index].w * i);
        if (index == n)
            res = max(res, cur_v);
        else
        {
            double tmp = (a[index + 1].v * cur_w) * 1.0 / a[index + 1].w;
            tmp += (cur_v * 1.0);
            if (tmp > res)
                Try(index + 1, cur_w, cur_v);
        }
        cur_v -= (a[index].v * i);
        cur_w += (a[index].w * i);
    }
}
int main()
{
    cin >> n >> W;
    for (ll i = 1; i <= n; i++)
        cin >> a[i].w;
    for (ll i = 1; i <= n; i++)
        cin >> a[i].v;
    sort(a + 1, a + 1 + n, cmp);
    Try(1, W, 0);
    cout << res;
    return 0;
}
