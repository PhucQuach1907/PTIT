#include <bits/stdc++.h>
using namespace std;
#define ld long double
#define ll long long
#define ull unsigned long long
struct Point
{
    double x, y;
};
struct Edge
{
    int head, tail;
    double weight;
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
double getDist(Point a, Point b)
{
    return hypot(a.x - b.x, a.y - b.y);
}
void Solve()
{
    int n;
    cin >> n;
    vector<Point> a(n);
    for (auto &A : a)
        cin >> A.x >> A.y;
    vector<Edge> E;
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
            E.push_back({i + 1, j + 1, getDist(a[i], a[j])});
    }
    sort(E.begin(), E.end(), cmp);
    vector<int> parent(n + 1, -1);
    double res = 0;
    int cnt = 0;
    for (int i = 0; i < (int)E.size(); i++)
    {
        int fi = Find(parent, E[i].head);
        int se = Find(parent, E[i].tail);
        if (fi != se)
        {
            res += E[i].weight;
            cnt++;
            Union(parent, fi, se);
            if (cnt == n - 1)
                break;
        }
    }
    cout << fixed << setprecision(6) << res << "\n";
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
