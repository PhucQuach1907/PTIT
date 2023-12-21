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
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++)
            cin >> a[i];
        int ans, tmp = INT_MAX;
        for (int i = 0; i < n - 1; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                int m = abs(0 - (a[i] + a[j]));
                if (m < tmp)
                {
                    tmp = m;
                    ans = a[i] + a[j];
                }
            }
        }
        cout << ans << "\n";
    }
    return 0;
}
