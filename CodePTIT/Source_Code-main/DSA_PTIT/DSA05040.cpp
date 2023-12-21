#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
void Solve()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &x : a)
        cin >> x;
    vector<int> l(n), r(n);
    l[0] = 1, r[n - 1] = 1;
    for (int i = 1, j = n - 2; i < n, j >= 0; i++, j--)
    {
        l[i] = (a[i] > a[i - 1] ? l[i - 1] + 1 : 1);
        r[j] = (a[j] > a[j + 1] ? r[j + 1] + 1 : 1);
    }
    int ans = -1;
    for (int i = 0; i < n; i++)
        ans = max(ans, l[i] + r[i] - 1);
    cout << ans << "\n";
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
