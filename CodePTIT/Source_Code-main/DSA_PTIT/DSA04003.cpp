#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
const ll MOD = 123456789;
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
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        ll n;
        cin >> n;
        n--;
        cout << Pow(2, n) << "\n";
    }
    return 0;
}
