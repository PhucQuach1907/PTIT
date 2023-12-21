#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
ll Count(ll l, ll r, ll x)
{
    if (l % x == 0)
        return (r / x) - (l / x) + 1;
    return (r / x) - (l / x);
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        ll l, r;
        cin >> l >> r;
        ll ans = Count(l, r, 4) + Count(l, r, 7) + Count(l, r, 11) - Count(l, r, 28) - Count(l, r, 44) - Count(l, r, 77) + Count(l, r, 308);
        cout << ans << "\n";
    }
    return 0;
}
