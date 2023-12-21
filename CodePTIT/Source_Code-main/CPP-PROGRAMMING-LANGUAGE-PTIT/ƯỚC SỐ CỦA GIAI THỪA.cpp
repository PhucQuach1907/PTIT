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
        int n, p, ans = 0;
        cin >> n >> p;
        while (n)
            ans += (n /= p);
        cout << ans << "\n";
    }
    return 0;
}