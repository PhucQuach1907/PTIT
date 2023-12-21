#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
char kthCharacter(ll n, ll pos)
{
    ll tmp = pow(2, n - 1);
    if (pos == tmp)
        return (n - 1 + 'A');
    if (pos > tmp)
        return kthCharacter(n - 1, pos - tmp);
    return kthCharacter(n - 1, pos);
}
void Solve()
{
    ll n, k;
    cin >> n >> k;
    cout << kthCharacter(n, k) << "\n";
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
