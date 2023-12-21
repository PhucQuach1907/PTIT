#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
const ll MAX = 1e5 + 5;
ll e[MAX];
ll Merge(ll a[], ll l, ll mid, ll r)
{
    ll lenl = mid - l + 1, lenr = r - mid;
    ll L[lenl], R[lenr];
    for (ll i = 0; i < lenl; i++)
        L[i] = a[i + l];
    for (ll i = 0; i < lenr; i++)
        R[i] = a[i + mid + 1];
    ll i = 0, j = 0, k = l;
    ll ans = 0;
    while (i < lenl && j < lenr)
    {
        if (L[i] <= R[j])
            a[k++] = L[i++];
        else
        {
            a[k++] = R[j++];
            ans += (lenl - i);
        }
    }
    while (i < lenl)
        a[k++] = L[i++];
    while (j < lenr)
        a[k++] = R[j++];
    return ans;
}
ll Inversion_Pair(ll a[], ll l, ll r)
{
    ll res = 0;
    if (l < r)
    {
        ll mid = (l + r) / 2;
        res += Inversion_Pair(a, l, mid);
        res += Inversion_Pair(a, mid + 1, r);
        res += Merge(a, l, mid, r);
    }
    return res;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll n;
    scanf("%lld", &n);
    vector<ll> a(n);
    ll len = 0;
    for (ll i = 0; i < n; i++)
    {
        scanf("%lld", &a[i]);
        if (a[i] % 2 == 0)
            e[len++] = a[i];
    }
    vector<ll> even;
    vector<vector<ll>> v;
    for (ll i = 0; i < n; i++)
    {
        if (a[i] & 1)
        {
            if (!even.empty())
            {
                v.push_back(even);
                even.clear();
            }
        }
        else
            even.push_back(a[i]);
    }
    if (!even.empty())
        v.push_back(even);
    ll ans = Inversion_Pair(e, 0, len - 1);
    for (ll i = 0; i < v.size(); i++)
    {
        len = 0;
        for (ll j = 0; j < v[i].size(); j++)
            e[len++] = v[i][j];
        ans -= Inversion_Pair(e, 0, len - 1);
    }
    printf("%lld", ans);
    return 0;
}
