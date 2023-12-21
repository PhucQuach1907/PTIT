#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
const int MAX = 1e3 + 5;
vector<int> adj[MAX];
bool vis[MAX];
int front[MAX];
void DFS(int s, int e)
{
    if (vis[e])
        return;
    vis[s] = true;
    for (int i = 0; i < adj[s].size(); i++)
    {
        if (!vis[adj[s][i]])
        {
            front[adj[s][i]] = s;
            DFS(adj[s][i], e);
        }
    }
}
void Trace(int s, int e)
{
    if (!vis[e])
    {
        cout << "KHONG TON TAI DUONG DI!";
        return;
    }
    vector<int> road;
    while (e != s)
    {
        road.push_back(e);
        e = front[e];
    }
    road.push_back(s);
    reverse(road.begin(), road.end());
    cout << "DFS path: ";
    for (auto x : road)
    {
        cout << x;
        if (x != road.back())
            cout << " -> ";
    }
    cout << "\n";
}
int main()
{
    memset(vis, false, sizeof(vis));
    int V, E, s, e;
    cout << "Nhap so dinh cua do thi: ";
    cin >> V;
    cout << "Nhap so canh cua do thi: ";
    cin >> E;
    cout << "Nhap dinh xuat phat: ";
    cin >> s;
    cout << "Nhap dinh ket thuc: ";
    cin >> e;
    cout << "Nhap cac canh cua do thi:\n";
    for (int i = 0; i < E; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    DFS(s, e);
    Trace(s, e);
    return 0;
}
