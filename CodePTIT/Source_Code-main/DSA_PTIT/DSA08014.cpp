#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
int n, m, a[505][505], vis[505][505];
struct Node
{
    int r, c, cnt;
};
bool canVisit(int i, int j)
{
    return (i > 0 && j > 0 && i <= n && j <= m && a[i][j] != 0 && !vis[i][j]);
}
void Solve()
{
    int R[] = {-1, 1, 0, 0};
    int C[] = {0, 0, -1, 1};
    memset(vis, false, sizeof(vis));
    cin >> n >> m;
    queue<Node> q;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cin >> a[i][j];
            if (a[i][j] == 2)
            {
                q.push({i, j, 0});
                vis[i][j] = true;
            }
        }
    }
    int ans = -1;
    while (!q.empty())
    {
        Node tmp = q.front();
        q.pop();
        ans = tmp.cnt;
        for (int i = 0; i < 4; i++)
        {
            if (canVisit(tmp.r + R[i], tmp.c + C[i]))
            {
                q.push({tmp.r + R[i], tmp.c + C[i], tmp.cnt + 1});
                vis[tmp.r + R[i]][tmp.c + C[i]] = true;
            }
        }
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (!vis[i][j] && a[i][j] != 0)
            {
                cout << -1 << "\n";
                return;
            }
        }
    }
    cout << ans << "\n";
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        Solve();
    }
    return 0;
}
