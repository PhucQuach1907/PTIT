#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
char a[2000][2000];
bool vis[2000][2000];
int n, m;
int row, col;
int cnt;
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, 1, -1};
struct Cow
{
    int x, y;
};
struct Fence
{
    int x1, y1, x2, y2;
};
vector<Cow> C(10000);
vector<Fence> F(10000);
void Init()
{
    set<int> s;
    map<int, int> shrink;
    // Chuan hoa toa do X
    for (int i = 0; i < n; i++)
    {
        s.insert(F[i].x1);
        s.insert(F[i].x2);
    }
    for (int i = 0; i < m; i++)
        s.insert(C[i].x);
    int d = 2;
    for (auto X : s)
        shrink[X] = d, d += 2;
    row = d + 10;
    for (int i = 0; i < n; i++)
    {
        F[i].x1 = shrink[F[i].x1];
        F[i].x2 = shrink[F[i].x2];
    }
    for (int i = 0; i < m; i++)
        C[i].x = shrink[C[i].x];
    s.clear(), shrink.clear();
    // Chuan hoa toa do Y
    for (int i = 0; i < n; i++)
    {
        s.insert(F[i].y1);
        s.insert(F[i].y2);
    }
    for (int i = 0; i < m; i++)
        s.insert(C[i].y);
    d = 2;
    for (auto X : s)
        shrink[X] = d, d += 2;
    col = d + 10;
    for (int i = 0; i < n; i++)
    {
        F[i].y1 = shrink[F[i].y1];
        F[i].y2 = shrink[F[i].y2];
    }
    for (int i = 0; i < m; i++)
        C[i].y = shrink[C[i].y];
    memset(a, '.', sizeof(a));
    for (int i = 0; i < n; i++)
    {
        for (int j = F[i].x1; j <= F[i].x2; j++)
        {
            for (int k = F[i].y1; k <= F[i].y2; k++)
                a[j][k] = 'X';
        }
    }
    for (int i = 0; i < m; i++)
        a[C[i].x][C[i].y] = 'C';
}
bool canVisit(int r, int c)
{
    return (r > 0 && c > 0 && r < row && c < col && a[r][c] != 'X' && !vis[r][c]);
}
void DFS(int r, int c)
{
    cnt += (a[r][c] == 'C' ? 1 : 0);
    vis[r][c] = true;
    for (int i = 0; i < 4; i++)
    {
        if (canVisit(r + dx[i], c + dy[i]))
            DFS(r + dx[i], c + dy[i]);
    }
}
void Solve()
{
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        cin >> F[i].x1 >> F[i].y1 >> F[i].x2 >> F[i].y2;
        if (F[i].x1 > F[i].x2)
            swap(F[i].x1, F[i].x2);
        if (F[i].y1 > F[i].y2)
            swap(F[i].y1, F[i].y2);
    }
    for (int i = 0; i < m; i++)
        cin >> C[i].x >> C[i].y;
    Init();
    memset(vis, false, sizeof(vis));
    int res = -1;
    for (int i = 0; i < m; i++)
    {
        if (!vis[C[i].x][C[i].y])
        {
            cnt = 0;
            DFS(C[i].x, C[i].y);
            res = max(res, cnt);
        }
    }
    cout << res << "\n";
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--)
    {
        Solve();
    }
    return 0;
}
