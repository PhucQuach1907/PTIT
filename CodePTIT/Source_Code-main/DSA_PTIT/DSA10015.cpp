#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
struct Edge
{
    int head, tail, weight;
};
bool cmp(Edge a, Edge b)
{
    return a.weight < b.weight;
}
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
    vector<Edge> a(E);
    for (auto &x : a)
        cin >> x.head >> x.tail >> x.weight;
    sort(a.begin(), a.end(), cmp);
    int res = 0, cnt = 0;
    ;
    vector<int> parent(V + 1, -1);
    for (int i = 0; i < E; i++)
    {
        int fi = Find(parent, a[i].head);
        int se = Find(parent, a[i].tail);
        if (fi != se)
        {
            res += a[i].weight;
            cnt++;
            Union(parent, fi, se);
            if (cnt == V - 1)
                break;
        }
    }
    cout << res << "\n";
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
