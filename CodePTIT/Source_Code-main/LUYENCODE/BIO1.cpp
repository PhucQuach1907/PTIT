#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
const ll P = 1e9 + 7;
ll nCk(ll n, ll k)
{
    ll C[k + 1];
    memset(C, 0, sizeof(C));
    C[0] = 1;
    for (ll i = 1; i <= n; i++)
    {
        for (ll j = min(i, k); j > 0; j--)
            C[j] = (C[j] + C[j - 1]) % P;
    }
    return C[k];
}
int main()
{
    ll n, k;
    cin >> k >> n;
    cout << nCk(n, k);
    return 0;
}
