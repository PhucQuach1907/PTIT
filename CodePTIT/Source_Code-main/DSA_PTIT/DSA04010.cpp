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
    int ans = INT_MIN, cur = 0;
    for (int i = 0; i < n; i++)
    {
        cur = max(cur + a[i], a[i]);
        ans = max(ans, cur);
    }
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
