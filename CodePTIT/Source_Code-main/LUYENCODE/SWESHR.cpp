#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
ll Candy(ll n, ll m)
{
    ll x = m * (m + 1) / 2;
    if (x > n)
        return -1;
    ll ans = -1;
    for (ll i = 1; i <= sqrt(n); i++)
    {
        if (n % i == 0)
        {
            ll div1 = i, div2 = n / i;
            ll remain = n - x * div1;
            if (remain >= 0 && remain % div1 == 0)
                ans = max(ans, div1);
            remain = n - x * div2;
            if (remain >= 0 && remain % div2 == 0)
                ans = max(ans, div2);
        }
    }
    return ans;
}
void Solve()
{
    ll n, m;
    cin >> n >> m;
    cout << Candy(n, m) << "\n";
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
