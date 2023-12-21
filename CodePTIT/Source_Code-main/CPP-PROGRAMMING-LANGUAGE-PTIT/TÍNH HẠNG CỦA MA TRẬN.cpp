#include <bits/stdc++.h>
using namespace std;
#define ui64 unsigned long long
int a[20][20];
void Swap_Two_Row(int row1, int row2, int m)
{
    for (int i = 1; i <= m; i++)
        swap(a[row1][i], a[row2][i]);
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m, rank = 0;
        cin >> n >> m;
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
                cin >> a[i][j];
        }
        int row = 1, col = 1;
        while (1)
        {
            if (row == n || col > m)
                break;
            if (!a[row][col])
            {
                for (int i = row + 1; i <= n; i++)
                {
                    if (a[i][col] != 0)
                    {
                        Swap_Two_Row(row, i, m);
                        break;
                    }
                }
            }
            if (!a[row][col])
                col++;
            else
            {
                for (int i = row + 1; i <= n; i++)
                {
                    if (a[i][col] != 0)
                    {
                        double mul = (double)a[i][col] / a[row][col];
                        for (int j = col; j <= m; j++)
                            a[i][j] -= mul * a[row][j];
                    }
                }
                col++, row++;
            }
        }
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                if (a[i][j] != 0)
                {
                    rank++;
                    break;
                }
            }
        }
        cout << rank << "\n";
    }
    return 0;
}