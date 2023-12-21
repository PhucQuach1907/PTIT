#include <bits/stdc++.h>
using namespace std;
#define ui64 unsigned long long
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        long long n;
        cin >> n;
        while (n % 2 == 0)
        {
            n /= 2;
            cout << 2 << " ";
        }
        for (int i = 3; i <= sqrt(n); i += 2)
        {
            while (n % i == 0)
            {
                n /= i;
                cout << i << " ";
            }
        }
        if (n > 2)
            cout << n;
        cout << "\n";
    }
    return 0;
}
