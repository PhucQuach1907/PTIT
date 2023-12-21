#include <bits/stdc++.h>
using namespace std;
#define ui64 unsigned long long
const int MOD = 1e9 + 7;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        long long n;
        cin >> n;
        vector<long long> fib(n + 1);
        fib[0] = 0, fib[1] = 1;
        for (long long i = 2; i <= n; i++)
            fib[i] = (fib[i - 2] + fib[i - 1]) % MOD;
        cout << fib[n] << "\n";
    }
    return 0;
}