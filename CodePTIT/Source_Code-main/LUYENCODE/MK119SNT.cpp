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
int main()
{
    Sieve();
    int pref[MAX];
    pref[0] = pref[1] = 0;
    for (int i = 2; i < MAX; i++)
    {
        if (isPrime[i])
            pref[i] = pref[i - 1] + 1;
        else
            pref[i] = pref[i - 1];
    }
    int t;
    cin >> t;
    while (t--)
    {
        int l, r;
        cin >> l >> r;
        cout << pref[r] - pref[l - 1] << "\n";
    }
    return 0;
}
