#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
int n, m;
char a[105][105];
int dr[] = {-1, -1, -1, 0, 0, 1, 1, 1};
int dc[] = {-1, 0, 1, -1, 1, -1, 0, 1};
bool canVisit(int i, int j)
{
    return (i > 0 && j > 0 && i <= n && j <= m && a[i][j] == 'W');
}
void DFS(int r, int c)
{
    if (!canVisit(r, c))
        return;
    a[r][c] = '.';
    for (int i = 0; i < 8; i++)
        DFS(r + dr[i], c + dc[i]);
}
int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
            cin >> a[i][j];
    }
    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (a[i][j] == 'W')
            {
                ans++;
                DFS(i, j);
            }
        }
    }
    cout << ans;
    return 0;
}
