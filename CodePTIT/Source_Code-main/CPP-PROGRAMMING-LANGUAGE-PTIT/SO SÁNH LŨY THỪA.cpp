#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        long long n, m, exception_count[5], ans = 0;
        memset(exception_count, 0, sizeof(exception_count));
        cin >> n >> m;
        vector<long long> x(n), y(m);
        for (auto &c : x)
            cin >> c;
        for (auto &c : y)
        {
            cin >> c;
            if (c < 5)
                exception_count[c]++;
        }
        sort(y.begin(), y.end());
        vector<long long>::iterator it;
        for (long long i = 0; i < n; i++)
        {
            if (x[i] == 0)
                continue;
            else if (x[i] == 1)
                ans += exception_count[0];
            else
            {
                it = upper_bound(y.begin(), y.end(), x[i]);
                ans += (m - (it - y.begin()));
                ans += (exception_count[0] + exception_count[1]);
            }
            if (x[i] == 2)
                ans -= (exception_count[3] + exception_count[4]);
            if (x[i] == 3)
                ans += exception_count[2];
        }
        cout << ans << "\n";
    }
    return 0;
}