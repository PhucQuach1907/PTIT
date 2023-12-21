#include <bits/stdc++.h>
using namespace std;
#define ui64 unsigned long long
#define ll long long
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int a[n + 1][n + 1], sum_row[n + 1], sum_col[n + 1], largest = -1, res = 0;
        memset(sum_row, 0, sizeof(sum_row));
        memset(sum_col, 0, sizeof(sum_col));
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                cin >> a[i][j];
                sum_row[i] += a[i][j];
                sum_col[j] += a[i][j];
            }
        }
        for (int i = 1; i <= n; i++)
            largest = max({largest, sum_row[i], sum_col[i]});
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                int add = largest - max(sum_row[i], sum_col[j]);
                res += add;
                sum_row[i] += add;
                sum_col[j] += add;
            }
        }
        cout << res << "\n";
    }
    return 0;
}