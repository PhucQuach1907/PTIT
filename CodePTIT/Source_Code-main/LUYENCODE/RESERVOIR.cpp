#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
void Solve()
{
    ll n;
    scanf("%lld", &n);
    vector<ll> pos(n + 1), h(n + 1), pref(n + 1);
    pos[0] = -1;
    for (ll i = 1; i <= n; i++)
        scanf("%lld", &pos[i]);
    for (ll i = 1; i <= n; i++)
        scanf("%lld", &h[i]);
    pref[0] = 0;
    for (ll i = 1; i <= n; i++)
        pref[i] = pref[i - 1] + h[i];
    vector<ll> larger(n + 1);
    stack<ll> stk;
    for (ll i = n; i > 0; i--)
    {
        if (stk.empty())
        {
            stk.push(i);
            continue;
        }
        while (!stk.empty() && h[i] >= h[stk.top()])
        {
            larger[stk.top()] = i;
            stk.pop();
        }
        stk.push(i);
    }
    while (!stk.empty())
    {
        larger[stk.top()] = 0;
        stk.pop();
    }
    vector<ll> query(n + 1);
    query[0] = 0;
    for (ll i = 1; i <= n; i++)
    {
        query[i] = query[larger[i]] + h[i] * (pos[i] - pos[larger[i]] - 1);
        ll l = larger[i] + 1, r = i - 1;
        query[i] -= (l <= r ? (pref[r] - pref[l - 1]) : 0);
    }
    ll q;
    scanf("%lld", &q);
    while (q--)
    {
        ll k;
        scanf("%lld", &k);
        int p = lower_bound(query.begin() + 1, query.end(), k) - query.begin();
        printf("%d\n", p - 1);
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    scanf("%d", &t);
    while (t--)
    {
        Solve();
    }
    return 0;
}
//Bài này trên luyencode mình nộp bị TLE mỗi test cuối, nhưng nộp lên trên kattis thì lại AC với 0.2s. Hic
//Link nộp trên kattis: https://open.kattis.com/problems/reservoir
