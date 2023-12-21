#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
int main()
{
    ll n;
    cin >> n;
    ll ans = 9e18;
    for (ll i = 1; i <= sqrt(n); i++)
    {
        if (n % i == 0)
        {
            ll x = i, y = n / i;
            ans = min(ans, x + y - 2);
        }
    }
    cout << ans;
    return 0;
}
