#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
int Find(vector<int> parent, int x)
{
    if (parent[x] == -1)
        return x;
    return Find(parent, parent[x]);
}
void Union(vector<int> &parent, int x, int y)
{
    parent[x] = y;
}
void Solve()
{
    int V, E;
    cin >> V >> E;
    vector<pair<int, int>> Edge(E);
    for (int i = 0; i < E; i++)
        cin >> Edge[i].first >> Edge[i].second;
    vector<int> parent(V + 1, -1);
    for (int i = 0; i < E; i++)
    {
        int x = Find(parent, Edge[i].first);
        int y = Find(parent, Edge[i].second);
        if (x == y)
        {
            cout << "YES\n";
            return;
        }
        Union(parent, x, y);
    }
    cout << "NO\n";
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
