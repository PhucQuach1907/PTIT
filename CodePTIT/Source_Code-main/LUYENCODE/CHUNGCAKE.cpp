#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
int main()
{
    long int c, gt[50][20000];
    long int w[50], n, j;
    cin >> n;
    cin >> c;
    for (int i = 1; i <= n; i++)
    {
        cin >> w[i];
    }
    w[0] = 0;
    gt[0][0] = 0;
    for (int i = 1; i <= n; i++)
    {
        gt[i][0] = 0;
    }
    for (int i = 1; i <= n; i++)
        for (j = 1; j <= c; j++)
        {
            if (w[i] <= j)
            {
                gt[i][j] = max(gt[i - 1][j - w[i]] + w[i], gt[i - 1][j]);
            }
            else
                gt[i][j] = gt[i - 1][j];
        }
    cout << gt[n][c];
}
