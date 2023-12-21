#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
int main()
{
    ll n;
    scanf("%lld", &n);
    ll lim = n / 3 - 1;
    ll ans = 0;
    if (n < 6)
    {
        printf("0");
        return 0;
    }
    for (ll i = 1; i <= lim; i++)
    {
        ll remain = n - i;
        ans += (remain & 1LL ? remain / 2 - i : remain / 2 - 1 - i);
    }
    printf("%lld", ans);
    return 0;
}
