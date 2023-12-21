#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
int main()
{
    int V, E;
    cout << "Nhap so dinh: ";
    cin >> V;
    cout << "Nhap so canh: ";
    cin >> E;
    vector<vector<int>> dis(V + 1, vector<int>(V + 1));
    vector<int> adj[V + 1];
    cout << "Nhap thong so cac canh:\n";
    for (int i = 0; i < E; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back(v);
        adj[v].push_back(u);
        dis[u][v] = dis[v][u] = w;
    }
    vector<int> parent(V + 1, -1), min_dis(V + 1, INT_MAX);
    vector<bool> vis(V + 1, false);
    vector<pair<int, int>> Prim_Edge;
    int Prim_Sum = 0;
    set<pair<int, int>> s;
    s.insert({0, 1});
    min_dis[1] = 0;
    while (!s.empty())
    {
        auto cur = *s.begin();
        vis[cur.second] = true;
        if (parent[cur.second] != -1)
            Prim_Edge.push_back({cur.second, parent[cur.second]});
        Prim_Sum += cur.first;
        s.erase(s.begin());
        for (auto x : adj[cur.second])
        {
            if (min_dis[x] > dis[cur.second][x] && !vis[x])
            {
                if (min_dis[x] != INT_MAX)
                    s.erase(s.find({min_dis[x], x}));
                min_dis[x] = dis[cur.second][x];
                s.insert({min_dis[x], x});
                parent[x] = cur.second;
            }
        }
    }
    cout << "Trong so cua cay bao trum nho nhat la: " << Prim_Sum << "\n";
    cout << "Cay bao trum nho nhat la:\n";
    for (auto x : Prim_Edge)
        cout << x.first << " " << x.second << "\n";
    return 0;
}
