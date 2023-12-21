#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
int dr[] = {-1, 0, 1, 0};
int dc[] = {0, 1, 0, -1};
struct Node
{
    int r, c, d;
    Node(int r, int c, int d) : r(r), c(c), d(d) {}
};
bool operator<(const Node &a, const Node &b)
{
    if (a.d == b.d)
    {
        if (a.r != b.r)
            return (a.r < b.r);
        return (a.c < b.c);
    }
    return (a.d < b.d);
}
bool isValid(int i, int j, int n, int m)
{
    return (i > 0 && j > 0 && i <= n && j <= m);
}
void Solve()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> dis(n + 1, vector<int>(m + 1)), dijkstra(n + 1, vector<int>(m + 1, INT_MAX));
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
            cin >> dis[i][j];
    }
    set<Node> s;
    s.insert(Node(1, 1, 0));
    dijkstra[1][1] = dis[1][1];
    while (!s.empty())
    {
        Node cur = *s.begin();
        s.erase(s.begin());
        for (int i = 0; i < 4; i++)
        {
            int new_r = cur.r + dr[i];
            int new_c = cur.c + dc[i];
            if (!isValid(new_r, new_c, n, m))
                continue;
            if (dijkstra[new_r][new_c] > dijkstra[cur.r][cur.c] + dis[new_r][new_c])
            {
                if (dijkstra[new_r][new_c] != INT_MAX)
                    s.erase(s.find(Node(new_r, new_c, dijkstra[new_r][new_c])));
                dijkstra[new_r][new_c] = dijkstra[cur.r][cur.c] + dis[new_r][new_c];
                s.insert(Node(new_r, new_c, dijkstra[new_r][new_c]));
            }
        }
    }
    cout << dijkstra[n][m] << "\n";
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
