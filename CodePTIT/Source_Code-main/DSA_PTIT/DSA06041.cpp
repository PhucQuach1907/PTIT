#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
void Solve()
{
    int n;
    cin >> n;
    vector<int> a(n);
    map<int, int> cnt;
    for (auto &x : a)
    {
        cin >> x;
        cnt[x]++;
    }
    int mid = n / 2, ans = -1, c = -1;
    for (auto x : cnt)
    {
        if (x.second > c)
        {
            c = x.second;
            ans = x.first;
        }
    }
    if (c > mid)
        cout << ans << "\n";
    else
        cout << "NO\n";
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
