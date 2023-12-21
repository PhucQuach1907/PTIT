#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
int kthNumber(ll n, ll pos)
{
    ll tmp = pow(2, n - 1);
    if (pos == tmp)
        return n;
    if (pos > tmp)
        return kthNumber(n - 1, pos - tmp);
    return kthNumber(n - 1, pos);
}
void Solve()
{
    ll n, k;
    cin >> n >> k;
    cout << kthNumber(n, k) << "\n";
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
