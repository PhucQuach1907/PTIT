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
        int n, k, less = 0, ans, bigger = 0;
        cin >> n >> k;
        vector<int> a(n);
        for (auto &c : a)
        {
            cin >> c;
            less += (c <= k ? 1 : 0);
        }
        for (int i = 0; i < less; i++)
            bigger += (a[i] > k ? 1 : 0);
        ans = bigger;
        for (int i = less; i < n; i++)
        {
            bigger -= (a[i - less] > k ? 1 : 0);
            bigger += (a[i] > k ? 1 : 0);
            ans = min(ans, bigger);
        }
        cout << ans << "\n";
    }
    return 0;
}