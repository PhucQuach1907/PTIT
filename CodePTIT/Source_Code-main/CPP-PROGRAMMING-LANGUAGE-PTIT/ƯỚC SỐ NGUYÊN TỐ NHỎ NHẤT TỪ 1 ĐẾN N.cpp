#include <bits/stdc++.h>
using namespace std;
const int MAX = 1e4 + 5;
int main()
{
    int Prime[MAX];
    memset(Prime, 1, sizeof(Prime));
    for (long long i = 2; i <= MAX / 2; i++)
    {
        if (Prime[i])
        {
            for (long long j = 2 * i; j < MAX; j += i)
                Prime[j] = 0;
        }
    }
    int t;
    cin >> t;
    while (t--)
    {
        long long n;
        cin >> n;
        for (long long i = 1; i <= n; i++)
        {
            int ok = 0;
            if (i == 1)
                cout << 1 << " ";
            else if (!(i%2))
                cout << 2 << " ";
            else
            {
                for (int j = 3; j <= sqrt(i); j += 2)
                {
                    if (Prime[j]  && i % j == 0)
                    {
                        ok = 1;
                        cout << j << " ";
                        break;
                    }
                }
                if (!ok)
                    cout << i << " ";
            }
        }
        cout << "\n";
    }
    return 0;
}