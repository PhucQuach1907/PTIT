#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
int n, k, a[30];
int Try(int pos, int remain)
{
    if (remain == 0)
        return 0;
    if (pos >= n)
        return a[n];
    return (a[pos] + max(Try(pos + 1, remain - 1), Try(pos + 2, remain - 1)));
}
signed main()
{
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    int res = -1;
    res = max(res, Try(1, k));
    res = max(res, Try(2, k));
    cout << res;
    return 0;
}
