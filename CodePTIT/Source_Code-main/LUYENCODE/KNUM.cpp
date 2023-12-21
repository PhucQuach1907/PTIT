#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
ll digit[10], pw[11];
void Set()
{
    pw[0] = 1LL;
    for (ll i = 1; i < 11; i++)
        pw[i] = pw[i - 1] * 10;
    digit[0] = 0LL;
    for (ll i = 1; i < 10; i++)
        digit[i] = digit[i - 1] + (9 * i * pw[i - 1]);
}
char Solve(ll n)
{
    ll pos;
    for (pos = 1; pos < 10; pos++)
    {
        if (digit[pos] >= n)
            break;
    }
    n -= digit[pos - 1];
    ll kth = ceil(n * 1.0 / pos);
    ll num = pw[pos - 1] + kth - 1;
    string m = to_string(num);
    if (n % pos == 0)
        return m.back();
    return m[(n % pos) - 1];
}
int main()
{
    Set();
    ll n;
    while (scanf("%lld", &n) == 1)
    {
        printf("%c\n", Solve(n));
    }
    return 0;
}
