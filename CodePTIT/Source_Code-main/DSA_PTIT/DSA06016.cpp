#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
void Solve()
{
    ll n, m;
    cin >> n >> m;
    vector<ll> a(n), b(m);
    for (auto &x : a)
        cin >> x;
    for (auto &x : b)
        cin >> x;
    ll A = *max_element(a.begin(), a.end());
    ll B = *min_element(b.begin(), b.end());
    ll ans = A * B;
    cout << ans << "\n";
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
