#include <bits/stdc++.h>
using namespace std;
#define ui64 unsigned long long
const double PI = 2 * acos(0);
const int MOD = 1e9 + 7;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        ui64 a, x, y;
        cin >> a >> x >> y;
        for (ui64 i = 1; i <= __gcd(x, y); i++)
            cout << a;
        cout << "\n";
    }
    return 0;
}