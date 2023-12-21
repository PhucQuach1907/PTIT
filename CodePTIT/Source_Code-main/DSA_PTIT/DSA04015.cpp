#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
void Solve()
{
    ll n, k;
    cin >> n >> k;
    vector<ll> a(n);
    for (auto &x : a)
        cin >> x;
    ll pos = upper_bound(a.begin(), a.end(), k) - a.begin() - 1;
    cout << (a[pos] <= k ? pos + 1 : -1) << "\n";
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
