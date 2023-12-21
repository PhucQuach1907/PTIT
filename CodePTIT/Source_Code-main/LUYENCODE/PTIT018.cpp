#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
ll fib[100];
char Solve(ll n, ll pos)
{
    if (n < 3)
        return (n == 1 ? 'A' : 'B');
    if (pos > fib[n - 2])
        return Solve(n - 1, pos - fib[n - 2]);
    else
        return Solve(n - 2, pos);
}
int main()
{
    fib[1] = fib[2] = 1LL;
    for (ll i = 3; i < 93; i++)
        fib[i] = fib[i - 2] + fib[i - 1];
    int t;
    cin >> t;
    while (t--)
    {
        ll n, pos;
        cin >> n >> pos;
        cout << Solve(n, pos) << "\n";
    }
    return 0;
}
