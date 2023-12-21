#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
char a[35][35][35];
bool vis[35][35][35];
int z, r, c;
int dz[] = {1, -1, 0, 0, 0, 0};
int dr[] = {0, 0, -1, 1, 0, 0};
int dc[] = {0, 0, 0, 0, -1, 1};
struct Node
{
    int z, R, C;
    int step;
};
bool canVisit(int h, int R, int C)
{
    return (h > 0 && R > 0 && C > 0 && h <= z && R <= r && C <= c && !vis[h][R][C] && a[h][R][C] != '#');
}
void Solve()
{
    memset(vis, false, sizeof(vis));
    Node start, end;
    cin >> z >> r >> c;
    for (int i = 1; i <= z; i++)
    {
        for (int j = 1; j <= r; j++)
        {
            for (int k = 1; k <= c; k++)
            {
                cin >> a[i][j][k];
                if (a[i][j][k] == 'S')
                    start = {i, j, k, 0};
                else if (a[i][j][k] == 'E')
                    end = {i, j, k, 0};
            }
        }
        cin.ignore();
    }
    queue<Node> q;
    q.push(start);
    vis[start.z][start.R][start.C] = true;
    while (!q.empty())
    {
        Node tmp = q.front();
        q.pop();
        if (tmp.z == end.z && tmp.R == end.R && tmp.C == end.C)
        {
            cout << tmp.step << "\n";
            return;
        }
        for (int i = 0; i < 6; i++)
        {
            int new_z = tmp.z + dz[i], new_R = tmp.R + dr[i], new_C = tmp.C + dc[i];
            if (canVisit(new_z, new_R, new_C))
            {
                q.push({new_z, new_R, new_C, tmp.step + 1});
                vis[new_z][new_R][new_C] = true;
            }
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
