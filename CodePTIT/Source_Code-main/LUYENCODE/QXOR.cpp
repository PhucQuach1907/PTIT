#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
const int N = 1e5 + 5;
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
    st[id] = st[id * 2] ^ st[id * 2 + 1];
}
void Update(int id, int pos, int l, int r, int val, int old_val)
{
    if (pos < l || pos > r)
        return;
    if (l == r)
    {
        st[id] = old_val ^ val;
        return;
    }
    int mid = (l + r) / 2;
    Update(id * 2, pos, l, mid, val, old_val);
    Update(id * 2 + 1, pos, mid + 1, r, val, old_val);
    st[id] = st[id * 2] ^ st[id * 2 + 1];
}
int Query(int id, int u, int v, int l, int r)
{
    if (u > r || v < l)
        return 0;
    if (u <= l && v >= r)
        return st[id];
    int mid = (l + r) / 2;
    int ln = Query(id * 2, u, v, l, mid);
    int rn = Query(id * 2 + 1, u, v, mid + 1, r);
    return (ln ^ rn);
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> q;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    Build(1, 1, n);
    while (q--)
    {
        int type, x, y;
        cin >> type >> x >> y;
        if (type == 1)
        {
            Update(1, x, 1, n, y, a[x]);
            a[x] ^= y;
        }
        else
            cout << Query(1, x, y, 1, n) << "\n";
    }
    return 0;
}
