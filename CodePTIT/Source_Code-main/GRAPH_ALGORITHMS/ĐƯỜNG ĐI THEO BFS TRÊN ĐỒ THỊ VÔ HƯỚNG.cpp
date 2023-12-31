#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
const int MAX = 1e3 + 5;
vector<int> adj[MAX];
bool vis[MAX];
int front[MAX];
void BFS(int s, int e)
{
    queue<int> q;
    q.push(s);
    vis[s] = true;
    while (!q.empty())
    {
        int temp = q.front();
        if (temp == e)
            break;
        q.pop();
        for (int i = 0; i < adj[temp].size(); i++)
        {
            if (!vis[adj[temp][i]])
            {
                vis[adj[temp][i]] = true;
                front[adj[temp][i]] = temp;
                q.push(adj[temp][i]);
            }
        }
    }
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
    cout << "BFS path: ";
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
    BFS(s, e);
    return 0;
}
