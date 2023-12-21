#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
const int N = 1e6 + 5;
int n, q, a[N], st[4 * N];
void Build(int id, int l, int r)
{
    if (l == r)
    {
        st[id] = a[l];
        return;
    }
    int m = (l + r) / 2;
    Build(2 * id, l, m);
    Build(2 * id + 1, m + 1, r);
    st[id] = min(st[id * 2], st[id * 2 + 1]);
}
int Query(int id, int u, int v, int l, int r)
{
    if (u > r || v < l)
        return INT_MAX;
    if (u <= l && v >= r)
        return st[id];
    int mid = (l + r) / 2;
    int ln = Query(id * 2, u, v, l, mid);
    int rn = Query(id * 2 + 1, u, v, mid + 1, r);
    return min(ln, rn);
}
int main()
{
    cin >> n >> q;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    Build(1, 1, n);
    while (q--)
    {
        int u, v;
        cin >> u >> v;
        cout << Query(1, u, v, 1, n) << " ";
    }
    return 0;
}
