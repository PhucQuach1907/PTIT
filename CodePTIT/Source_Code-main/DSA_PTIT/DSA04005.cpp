#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
ll fib[95];
char kthCharacter(ll n, ll pos)
{
    if (n == 1)
        return 'A';
    if (n == 2)
        return 'B';
    if (pos <= fib[n - 2])
        return kthCharacter(n - 2, pos);
    return kthCharacter(n - 1, pos - fib[n - 2]);
}
void Solve()
{
    ll n, pos;
    cin >> n >> pos;
    cout << kthCharacter(n, pos) << "\n";
}
int main()
{
    fib[1] = fib[2] = 1;
    for (ll i = 3; i < 93; i++)
        fib[i] = fib[i - 1] + fib[i - 2];
    int t;
    cin >> t;
    while (t--)
    {
        Solve();
    }
    return 0;
}
