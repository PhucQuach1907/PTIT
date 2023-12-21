#include <bits/stdc++.h>
using namespace std;
int V, E, path[100];
vector<vector<int>> euler_path, euler_circuit;
int start;
void DFS(vector<int> adj[], vector<vector<bool>> &vis, int cur, int idx)
{
    path[idx] = cur;
    if (idx == E + 1)
    {
        if (path[idx] == start)
            euler_circuit.push_back({path + 1, path + idx + 1});
        else
            euler_path.push_back({path + 1, path + idx + 1});
        return;
    }
    for (auto x : adj[cur])
    {
        if (!vis[cur][x] && !vis[x][cur])
        {
            vis[cur][x] = vis[x][cur] = true;
            DFS(adj, vis, x, idx + 1);
            vis[cur][x] = vis[x][cur] = false;
        }
    }
}
void Print_Path(vector<int> v)
{
    for (int i = 0; i < (int)v.size(); i++)
    {
        cout << v[i];
        if (i != (int)v.size() - 1)
            cout << " -> ";
    }
    cout << "\n";
}
int main()
{
    cout << "Nhap so dinh cua do thi: ";
    cin >> V;
    cout << "Nhap so canh cua do thi: ";
    cin >> E;
    vector<int> adj[V + 1];
    cout << "Nhap cac canh cua do thi:\n";
    for (int i = 0; i < E; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    for (int i = 1; i <= V; i++)
    {
        start = i;
        vector<vector<bool>> vis(V + 1, vector<bool>(V + 1, false));
        DFS(adj, vis, i, 1);
    }
    if (euler_path.size() == 0 && euler_circuit.size() == 0)
    {
        cout << "KHONG TON TAI DUONG DI HOAC CHU TRINH EULER!";
        return 0;
    }
    cout << "SO LUONG DUONG DI EULER: " << euler_path.size() << "\n";
    if (euler_path.size() > 0)
    {
        cout << "CAC DUONG DI EULER:\n";
        for (auto x : euler_path)
            Print_Path(x);
    }
    cout << "\nSO LUONG CHU TRINH EULER: " << euler_circuit.size() << "\n";
    if (euler_circuit.size() > 0)
    {
        cout << "CAC CHU TRINH EULER:\n";
        for (auto x : euler_circuit)
            Print_Path(x);
    }
    return 0;
}
