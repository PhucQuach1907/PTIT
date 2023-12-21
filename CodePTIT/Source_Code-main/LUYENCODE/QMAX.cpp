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
    st[id] = max(st[id * 2], st[id * 2 + 1]);
}
void Update(int id, int l, int r, int pos, int val)
{
    if (pos < l || pos > r)
        return;
    if (l == r)
    {
        st[id] = val;
        return;
    }
    int mid = (l + r) / 2;
    Update(id * 2, l, mid, pos, val);
    Update(id * 2 + 1, mid + 1, r, pos, val);
    st[id] = max(st[id * 2], st[id * 2 + 1]);
}
int Query(int id, int u, int v, int l, int r)
{
    if (u > r || v < l)
        return INT_MIN;
    if (u <= l && v >= r)
        return st[id];
    int mid = (l + r) / 2;
    int ln = Query(id * 2, u, v, l, mid);
    int rn = Query(id * 2 + 1, u, v, mid + 1, r);
    return max(ln, rn);
}
int main()
{
    cin >> n >> q;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    Build(1, 1, n);
    while (q--)
    {
        int type, a, b;
        cin >> type >> a >> b;
        if (type == 1)
            Update(1, 1, n, a, b);
        else
            cout << Query(1, a, b, 1, n) << " ";
    }
    return 0;
}
