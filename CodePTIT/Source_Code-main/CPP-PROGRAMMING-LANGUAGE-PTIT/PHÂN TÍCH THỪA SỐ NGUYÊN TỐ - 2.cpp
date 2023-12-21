#include <bits/stdc++.h>
using namespace std;
#define ui64 unsigned long long
#define ll long long
int main()
{
    int n, expo = 0;
    cin >> n;
    while (n % 2 == 0)
    {
        n /= 2;
        expo++;
    }
    if (expo)
        cout << 2 << " " << expo << "\n";
    for (int i = 3; i <= sqrt(n); i += 2)
    {
        if (n % i == 0)
        {
            expo = 0;
            while (n % i == 0)
            {
                n /= i;
                expo++;
            }
            if (expo)
                cout << i << " " << expo << "\n";
        }
    }
    if (n > 2)
        cout << n << " " << 1 << "\n";
    return 0;
}