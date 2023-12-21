#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
void Solve()
{
    ll n;
    cin >> n;
    vector<ll> a(n), b(n - 1);
    for (auto &x : a)
        cin >> x;
    for (auto &x : b)
        cin >> x;
    auto pos = mismatch(a.begin(), a.end(), b.begin());
    cout << pos.first - a.begin() + 1 << "\n";
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
