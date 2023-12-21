#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
int main()
{
    ll n, m;
    cin >> n >> m;
    ll ans = (n / 2) * (m / 2);
    ll remain = n * m - 4 * ans;
    ans += (remain + 1) / 2;
    cout << ans;
    return 0;
}
