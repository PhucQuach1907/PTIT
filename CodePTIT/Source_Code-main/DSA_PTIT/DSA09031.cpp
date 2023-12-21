#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
int n, k, m, cnt;
bool Fence[105][105][4];
// 0: Tren, 1: Duoi, 2: Trai, 3: Phai
bool Sheep[105][105], vis[105][105];
vector<int> a;
int dr[] = {-1, 1, 0, 0};
int dc[] = {0, 0, -1, 1};
bool canVisit(int start_r, int start_c, int des_r, int des_c)
{
    return (des_r > 0 && des_r <= n && des_c > 0 && des_c <= n && !vis[des_r][des_c]);
}
void DFS(int i, int j)
{
    vis[i][j] = true;
    cnt += (Sheep[i][j] ? 1 : 0);
    for (int x = 0; x < 4; x++)
    {
        if (canVisit(i, j, i + dr[x], j + dc[x]) && !Fence[i][j][x])
            DFS(i + dr[x], j + dc[x]);
    }
}
int main()
{
    cin >> n >> k >> m;
    for (int i = 0; i < m; i++)
    {
        int r1, c1, r2, c2;
        cin >> r1 >> c1 >> r2 >> c2;
        if (r1 == r2)
        {
            if (c2 > c1)
                Fence[r1][c1][3] = Fence[r2][c2][2] = 1;
            else
                Fence[r1][c1][2] = Fence[r2][c2][3] = 1;
        }
        else
        {
            if (r2 > r1)
                Fence[r1][c1][1] = Fence[r2][c2][0] = 1;
            else
                Fence[r1][c1][0] = Fence[r2][c2][1] = 1;
        }
    }
    for (int i = 0; i < k; i++)
    {
        int r, c;
        cin >> r >> c;
        Sheep[r][c] = 1;
    }
    cnt = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (Sheep[i][j] && !vis[i][j])
            {
                DFS(i, j);
                a.push_back(cnt);
                cnt = 0;
            }
        }
    }
    int ans = 0;
    for (int i = 0; i < (int)a.size() - 1; i++)
    {
        for (int j = i + 1; j < (int)a.size(); j++)
            ans += a[i] * a[j];
    }
    cout << ans;
    return 0;
}
