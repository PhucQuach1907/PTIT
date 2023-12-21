#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
const int MAX = 1e5 + 5;
int n, q, a[MAX], BIT[MAX];
void Update(int idx, int val)
{
    while (idx <= n)
    {
        BIT[idx] += val;
        idx += idx & (-idx);
    }
}
int getSum(int idx)
{
    int sum = 0;
    while (idx > 0)
    {
        sum += BIT[idx];
        idx -= idx & (-idx);
    }
    return sum;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> q;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        Update(i, a[i]);
    }
    while (q--)
    {
        int type;
        cin >> type;
        if (type == 1)
        {
            int pos, val;
            cin >> pos >> val;
            Update(pos, val);
        }
        else
        {
            int l, r;
            cin >> l >> r;
            cout << getSum(r) - getSum(l - 1) << " ";
        }
    }
    return 0;
}
