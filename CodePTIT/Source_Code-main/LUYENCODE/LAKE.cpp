#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
int n, m, k, a[105][105], cnt, res;
bool vis[105][105];
bool canVisit(int r, int c)
{
    return (r >= 1 && r <= n && c >= 1 && c <= m && !vis[r][c] && a[r][c] == 1);
}
void DFS(int i, int j)
{
    if (!canVisit(i, j))
        return;
    cnt++;
    vis[i][j] = true;
    DFS(i - 1, j);
    DFS(i + 1, j);
    DFS(i, j - 1);
    DFS(i, j + 1);
}
int main()
{
    res = 0, cnt = 0;
    memset(vis, false, sizeof(vis));
    cin >> n >> m >> k;
    memset(a, 0, sizeof(a));
    while (k--)
    {
        int r, c;
        cin >> r >> c;
        a[r][c] = 1;
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (a[i][j] == 1 && !vis[i][j])
            {
                DFS(i, j);
                res = max(res, cnt);
                cnt = 0;
            }
        }
    }
    cout << res;
    return 0;
}
