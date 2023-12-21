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
        int ans = 0;
        for (int i = 0; i < n - 1; i++)
        {
            int val = a[i], pos = i;
            for (int j = i + 1; j < n; j++)
            {
                {
                    if (a[j] < val)
                    {
                        val = a[j];
                        pos = j;
                    }
                }
            }
            ans += (a[i] > a[pos] ? 1 : 0);
            swap(a[i], a[pos]);
        }
        cout << ans << "\n";
    }
    return 0;
}
