#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
const int MAX = 1e4 + 5;
int parent[MAX], sz[MAX];
int Find(int v)
{
    if (v == parent[v])
        return v;
    return (parent[v] = Find(parent[v]));
}
void makeSet(int n)
{
    for (int i = 1; i <= n; i++)
        parent[i] = i, sz[i] = 1;
}
void Union(int u, int v)
{
    int a = Find(u);
    int b = Find(v);
    if (a != b)
    {
        if (sz[a] < sz[b])
            swap(a, b);
        parent[b] = a;
        sz[a] += sz[b];
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    makeSet(MAX - 1);
    int q;
    cin >> q;
    while (q--)
    {
        int u, v, type;
        cin >> u >> v >> type;
        if (type == 1)
            Union(u, v);
        else
        {
            int lead_u = Find(u);
            int lead_v = Find(v);
            cout << (lead_u == lead_v) << "\n";
        }
    }
    return 0;
}
