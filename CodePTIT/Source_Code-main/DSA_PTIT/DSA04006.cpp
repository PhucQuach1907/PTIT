#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
ll Find(ll pos, ll n, ll ctr)
{
    if (pos & 1)
        return 1;
    if (pos == ctr)
        return (n % 2);
    if (pos > ctr)
        return Find(pos - ctr, n / 2, ctr / 2);
    return Find(pos, n / 2, ctr / 2);
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        ll n, l, r;
        cin >> n >> l >> r;
        ll ctr = pow(2, (ll)log2(n)), ans = 0;
        for (ll i = l; i <= r; i++)
            ans += Find(i, n, ctr);
        cout << ans << "\n";
    }
    return 0;
}
