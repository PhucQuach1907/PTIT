#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define ull unsigned long long
int dx[] = {-2, -2, -1, 1, 2, 2, 1, -1};
int dy[] = {-1, 1, 2, 2, 1, -1, -2, -2};
struct Node
{
    int r, c;
    int step;
};
bool canVisit(int r, int c, vector<vector<bool>> vis)
{
    return (r > 0 && c > 0 && r < 9 && c < 9 && !vis[r][c]);
}
void Solve()
{
    string a, b;
    cin >> a >> b;
    int sr = a.back() - '0', sc = a.front() - 96, tr = b.back() - '0', tc = b.front() - 96;
    vector<vector<bool>> vis(10, vector<bool>(10, false));
    queue<Node> q;
    q.push({sr, sc, 0});
    vis[sr][sc] = true;
    while (!q.empty())
    {
        Node cur = q.front();
        q.pop();
        if (cur.r == tr && cur.c == tc)
        {
            cout << cur.step << "\n";
            return;
        }
        for (int i = 0; i < 8; i++)
        {
            if (canVisit(cur.r + dx[i], cur.c + dy[i], vis))
            {
                q.push({cur.r + dx[i], cur.c + dy[i], cur.step + 1});
                vis[cur.r + dx[i]][cur.c + dy[i]] = true;
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
