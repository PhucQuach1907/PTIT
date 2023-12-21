#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define ull unsigned long long
struct Node
{
    int row, col;
    int count;
};
void Solve()
{
    int n, m;
    cin >> n >> m;
    int a[n + 1][m + 1];
    bool vis[n + 1][m + 1];
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
            cin >> a[i][j];
    }
    memset(vis, false, sizeof(vis));
    Node mid;
    mid.row = mid.col = 1;
    mid.count = 0;
    queue<Node> q;
    q.push(mid);
    vis[1][1] = true;
    while (!q.empty())
    {
        Node temp = q.front();
        q.pop();
        if ((temp.row == n && temp.col + a[temp.row][temp.col] == m) || (temp.col == m && temp.row + a[temp.row][temp.col] == n))
        {
            cout << temp.count + 1 << "\n";
            return;
        }
        if (temp.row + a[temp.row][temp.col] <= n && !vis[temp.row + a[temp.row][temp.col]][temp.col])
        {
            Node m;
            m.row = temp.row + a[temp.row][temp.col];
            m.col = temp.col;
            m.count = temp.count + 1;
            q.push(m);
            vis[m.row][m.col] = true;
        }
        if (temp.col + a[temp.row][temp.col] <= m && !vis[temp.row][temp.col + a[temp.row][temp.col]])
        {
            Node m;
            m.row = temp.row;
            m.col = temp.col + a[temp.row][temp.col];
            m.count = temp.count + 1;
            q.push(m);
            vis[m.row][m.col] = true;
        }
    }
    cout << -1 << "\n";
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
