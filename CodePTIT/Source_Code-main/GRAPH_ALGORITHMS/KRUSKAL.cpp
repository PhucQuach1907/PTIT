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
int main()
{
    int V, E;
    cout << "Nhap so dinh: ";
    cin >> V;
    cout << "Nhap so canh: ";
    cin >> E;
    vector<Edge> a(E);
    cout << "Nhap thong so cac canh:\n";
    for (auto &x : a)
        cin >> x.head >> x.tail >> x.weight;
    sort(a.begin(), a.end(), cmp);
    int dH = 0;
    vector<pair<int, int>> ans;
    vector<int> parent(V + 1, -1);
    for (int i = 0; i < E; i++)
    {
        int fi = Find(parent, a[i].head);
        int se = Find(parent, a[i].tail);
        if (fi != se)
        {
            dH += a[i].weight;
            ans.push_back({a[i].head, a[i].tail});
            Union(parent, fi, se);
            if (ans.size() == V - 1)
                break;
        }
    }
    cout << "Trong so cua cay bao trum nho nhat: " << dH << "\n";
    cout << "Cay bao trum nho nhat la:\n";
    for (auto x : ans)
        cout << x.first << " " << x.second << "\n";
    return 0;
}
