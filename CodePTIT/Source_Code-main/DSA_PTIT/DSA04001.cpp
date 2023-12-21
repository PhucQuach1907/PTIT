#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
const ll MOD = 1e9 + 7;
ll Pow(ll n, ll k)
{
    ll ans = 1;
    while (k)
    {
        if (k & 1)
            ans = (ans * n) % MOD;
        n = (n * n) % MOD;
        k >>= 1;
    }
    return ans;
}
void Solve()
{
    ll n, k;
    cin >> n >> k;
    cout << Pow(n, k) << "\n";
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
