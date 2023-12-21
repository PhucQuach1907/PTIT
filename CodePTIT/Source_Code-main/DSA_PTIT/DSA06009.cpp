#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        vector<int> a(n);
        for (auto &x : a)
            cin >> x;
        int ans = 0;
        for (int i = 0; i < n - 1; i++)
        {
            for (int j = i + 1; j < n; j++)
                ans += (a[i] + a[j] == k ? 1 : 0);
        }
        cout << ans << "\n";
    }
    return 0;
}
