#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
ll Calc(vector<ll> a, ll n, ll k, map<ll, ll> cnt)
{
    ll ans = 0;
    for (ll i = 0; i < n; i++)
    {
        ans += cnt[k - a[i]];
        if (k - a[i] == a[i])
            ans--;
    }
    return ans / 2;
}
void Solve()
{
    ll n, k;
    cin >> n >> k;
    vector<ll> a(n);
    map<ll, ll> cnt;
    for (auto &x : a)
    {
        cin >> x;
        cnt[x]++;
    }
    cout << Calc(a, n, k, cnt) << "\n";
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
