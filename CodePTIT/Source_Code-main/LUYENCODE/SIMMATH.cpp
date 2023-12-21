#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
const ll MOD = 998244353;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        ll a, b, c;
        cin >> a >> b >> c;
        ll m1 = a * (a + 1) / 2, m2 = b * (b + 1) / 2, m3 = c * (c + 1) / 2;
        m1 %= MOD, m2 %= MOD, m3 %= MOD;
        ll res = (m1 * m2) % MOD;
        res = (res * m3) % MOD;
        cout << res << "\n";
    }
    return 0;
}
