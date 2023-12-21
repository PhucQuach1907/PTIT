#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int V, E;
    scanf("%d%d", &V, &E);
    vector<vector<int>> dis(V + 1, vector<int>(V + 1, 1e9));
    for (int i = 0; i < E; i++)
    {
        int u, v, d;
        scanf("%d%d%d", &u, &v, &d);
        dis[u][v] = dis[v][u] = d;
    }
    vector<vector<int>> floyd = dis;
    for (int i = 1; i <= V; i++)
        floyd[i][i] = 0;
    for (int mid = 1; mid <= V; mid++)
    {
        for (int i = 1; i <= V; i++)
        {
            for (int j = 1; j <= V; j++)
                floyd[i][j] = min(floyd[i][j], floyd[i][mid] + floyd[mid][j]);
        }
    }
    int q;
    scanf("%d", &q);
    while (q--)
    {
        int u, v;
        scanf("%d%d", &u, &v);
        printf("%d\n", floyd[u][v]);
    }
    return 0;
}
