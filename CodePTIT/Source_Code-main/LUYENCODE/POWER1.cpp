#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
const ll MOD = 1e9 + 7;
ll Pow(ll a, ll n)
{
    ll res = 1;
    while (n)
    {
        if (n & 1)
            res = (res * a) % MOD;
        a = (a * a) % MOD;
        n /= 2;
    }
    return res;
}
int main()
{
    ll a, n;
    cin >> a >> n;
    cout << Pow(a, n);
    return 0;
}
