#include <bits/stdc++.h>
using namespace std;
#define ui64 unsigned long long
#define ll long long
int a[60][60], b[60][60], n, m, p;
int Calculate(int row, int col)
{
    int res = 0;
    for (int i = 1; i <= m; i++)
        res += (a[row][i] * b[i][col]);
    return res;
}
int main()
{
    cin >> n >> m >> p;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
            cin >> a[i][j];
    }
    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= p; j++)
            cin >> b[i][j];
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= p; j++)
            cout << Calculate(i, j) << " ";
        cout << "\n";
    }
    return 0;
}