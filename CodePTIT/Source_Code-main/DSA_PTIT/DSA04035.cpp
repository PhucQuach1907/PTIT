#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
const ll MOD = 1e9 + 7;
ll Pow(ll a, ll b)
{
    ll res = 1;
    while (b)
    {
        if (b & 1)
            res = (res * a) % MOD;
        a = (a * a) % MOD;
        b >>= 1;
    }
    return res;
}
int main()
{
    ll a, b;
    while (1)
    {
        cin >> a >> b;
        if (a == 0 && b == 0)
            break;
        cout << Pow(a, b) << "\n";
    }
    return 0;
}
