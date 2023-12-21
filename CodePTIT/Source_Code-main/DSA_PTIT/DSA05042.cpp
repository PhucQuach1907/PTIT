#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
bool isExist(ll n, ll k, vector<ll> a)
{
    unordered_map<ll, bool> v;
    ll pref = 0;
    for (ll i = 0; i < n; i++)
    {
        pref += a[i];
        if (pref == k)
            return true;
        if (v[pref - k] == true)
            return true;
        v[pref] = true;
    }
    return false;
}
void Solve()
{
    ll n, k;
    cin >> n >> k;
    vector<ll> a(n);
    for (auto &x : a)
        cin >> x;
    cout << (isExist(n, k, a) ? "YES\n" : "NO\n");
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
