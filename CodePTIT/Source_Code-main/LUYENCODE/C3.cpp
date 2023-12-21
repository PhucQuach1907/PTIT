#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
int main()
{
    ll n, k;
    cin >> n >> k;
    vector<ll> a(n);
    map<ll, ll> cnt;
    ll res = 0;
    for (auto &x : a)
    {
        cin >> x;
        cnt[x]++;
        res += cnt[k - x * x];
    }
    cout << res;
    return 0;
}
