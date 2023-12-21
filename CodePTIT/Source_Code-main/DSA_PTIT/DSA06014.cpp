#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
const int MAX = 1e6 + 5;
bool isPrime[MAX];
void Sieve()
{
    memset(isPrime, true, sizeof(isPrime));
    isPrime[0] = isPrime[1] = false;
    for (int i = 2; i <= MAX / 2; i++)
    {
        if (isPrime[i])
        {
            for (int j = 2 * i; j < MAX; j += i)
                isPrime[j] = false;
        }
    }
}
void Solve()
{
    int n;
    cin >> n;
    for (int i = 2; i <= n / 2; i++)
    {
        if (isPrime[i] && isPrime[n - i])
        {
            cout << i << " " << n - i << "\n";
            return;
        }
    }
    cout << -1 << "\n";
}
int main()
{
    Sieve();
    int t;
    cin >> t;
    while (t--)
    {
        Solve();
    }
    return 0;
}
