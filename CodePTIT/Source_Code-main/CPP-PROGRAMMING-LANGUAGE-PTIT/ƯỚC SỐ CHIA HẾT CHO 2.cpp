#include <bits/stdc++.h>
using namespace std;
#define ui64 unsigned long long
#define ll long long
int mat[105][105];
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, res = 1, count = 0;
        cin >> n;
        if (n & 1)
        {
            cout << 0 << "\n";
            continue;
        }
        while (n % 2 == 0)
        {
            n /= 2;
            count++;
        }
        res *= count;
        for (int i = 3; i <= sqrt(n); i++)
        {
            count = 0;
            while (n % i == 0)
            {
                n /= i;
                count++;
            }
            res *= (count + 1);
        }
        res *= (n > 2 ? 2 : 1);
        cout << res << "\n";
    }
    return 0;
}