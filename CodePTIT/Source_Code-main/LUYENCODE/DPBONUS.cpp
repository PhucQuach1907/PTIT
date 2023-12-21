#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, k;
    cin >> n >> k;
    vector<vector<int>> a(n + 1, vector<int>(n + 1, 0));
    int res = -1;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cin >> a[i][j];
            a[i][j] += a[i - 1][j] + a[i][j - 1] - a[i - 1][j - 1];
            if (i >= k && j >= k)
                res = max(res, a[i][j] - a[i - k][j] - a[i][j - k] + a[i - k][j - k]);
        }
    }
    cout << res;
    return 0;
}
