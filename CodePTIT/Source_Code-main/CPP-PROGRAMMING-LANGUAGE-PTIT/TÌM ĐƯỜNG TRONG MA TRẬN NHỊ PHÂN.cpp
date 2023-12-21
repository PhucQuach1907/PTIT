#include <bits/stdc++.h>
using namespace std;
const pair<int, int> go[4] = {{0,-1,},{-1, 0},{1, 0},{0, 1}};
int a[1005][1005], dist[1005][1005];
bool vis[1005][1005];
const int INF = 1e9;
int main()
{
    int tc;
    cin >> tc;
    while (tc--)
    {
        int m, n;
        int x1, y1, x2, y2;
        cin >> m >> n >> x1 >> y1 >> x2 >> y2;
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                cin >> a[i][j];
        auto Banned = [&](int x, int y)
        {
            return x < 0 || y < 0 || x > m - 1 || y > n - 1 || a[x][y] == 0;
        };
        queue<pair<int, int>> q;
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                dist[i][j] = INF;
        dist[x1][y1] = (a[x1][y1] == 0 ? INF : 0);
        memset(vis, 0, sizeof vis);
        vis[x1][y1] = true;
        q.push(make_pair(x1, y1));
        while (!q.empty())
        {
            int x, y;
            tie(x, y) = q.front();
            q.pop();
            for (int i = 0; i < 4; i++)
            {
                int u = x + go[i].first;
                int v = y + go[i].second;
                if (Banned(u, v))
                    continue;
                if (vis[u][v])
                    continue;

                vis[u][v] = true;
                dist[u][v] = dist[x][y] + 1;
                q.push(make_pair(u, v));
            }
        }
        cout << (dist[x2][y2] >= INF ? -1 : dist[x2][y2]) << "\n";
    }
}