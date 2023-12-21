#include <bits/stdc++.h>
using namespace std;
#define ui64 unsigned long long
#define ll long long
int main()
{

    int t;
    cin >> t;
    while (t--)
    {
        ll n, ans;
        cin >> n;
        ll a[n];
        for (ll i = 0; i < n; i++)
            cin >> a[i];
        ans = a[0];
        for (ll i = 0; i < n - 1; i++)
        {
            ll tmp = a[i];
            for (ll j = i + 1; j < n; j++)
            {
                ans = max(ans, tmp);
                tmp *= a[j];
            }
            ans = max(ans, tmp);
        }
        cout << ans << "\n";
    }
    return 0;
}