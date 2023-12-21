#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
const ll MOD = 1e9 + 7;
ll Rev(ll n)
{
    ll b = 0;
    while (n > 0)
    {
        int a = n % 10;
        b = b * 10 + a;
        n /= 10;
    }
    return b;
}
ll Pow(ll a, ll n)
{
    if (n == 0)
        return 1;
    if (n == 1)
        return a % MOD;
    ll x = Pow(a, n / 2);
    if (n % 2 == 0)
        return x * x % MOD;
    else
        return x * x % MOD * a % MOD;
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        ll n;
        cin >> n;
        ll r = Rev(n);
        cout << Pow(n, r) << "\n";
    }
}
