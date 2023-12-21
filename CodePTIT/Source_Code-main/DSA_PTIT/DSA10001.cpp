#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
struct Node
{
    int row, col;
    int count;
};
void Solve()
{
    int n, m, a, b, c, d;
    cin >> n >> m;
    char mat[n + 1][m + 1];
    bool vis[n + 1][m + 1];
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cin >> mat[i][j];
            if (mat[i][j] == 'S')
                a = i, b = j;
            if (mat[i][j] == 'T')
                c = i, d = j;
        }
    }
    memset(vis, false, sizeof(vis));
    queue<Node> q;
    q.push({a, b, -1});
    vis[a][b] = true;
    while (!q.empty())
    {
        Node cur = q.front();
        q.pop();
        if (cur.count > 2)
        {
            cout << "NO\n";
            return;
        }
        if (cur.row == c && cur.col == d)
        {
            if (cur.count <= 2)
            {
                cout << "YES\n";
                return;
            }
        }
        // Down
        for (int i = cur.row; i <= n; i++)
        {
            if (mat[i][cur.col] == '*')
                break;
            if (!vis[i][cur.col])
            {
                q.push({i, cur.col, cur.count + 1});
                vis[i][cur.col] = true;
            }
        }
        // Up
        for (int i = cur.row; i > 0; i--)
        {
            if (mat[i][cur.col] == '*')
                break;
            if (!vis[i][cur.col])
            {
                q.push({i, cur.col, cur.count + 1});
                vis[i][cur.col] = true;
            }
        }
        // Right
        for (int i = cur.col; i <= m; i++)
        {
            if (mat[cur.row][i] == '*')
                break;
            if (!vis[cur.row][i])
            {
                q.push({cur.row, i, cur.count + 1});
                vis[cur.row][i] = true;
            }
        }
        // Left
        for (int i = cur.col; i > 0; i--)
        {
            if (mat[cur.row][i] == '*')
                break;
            if (!vis[cur.row][i])
            {
                q.push({cur.row, i, cur.count + 1});
                vis[cur.row][i] = true;
            }
        }
    }
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
