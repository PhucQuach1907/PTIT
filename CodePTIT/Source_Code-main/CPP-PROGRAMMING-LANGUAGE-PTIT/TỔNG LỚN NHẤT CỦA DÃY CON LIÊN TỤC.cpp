#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<long long> a(n);
        for (auto &c : a)
            cin >> c;
        long long sum = 0, ans = INT_MIN;
        for (int i = 0; i < n; i++)
        {
            sum = max(a[i], sum + a[i]);
            ans = max(ans, sum);
        }
        cout << ans << "\n";
    }
    return 0;
}