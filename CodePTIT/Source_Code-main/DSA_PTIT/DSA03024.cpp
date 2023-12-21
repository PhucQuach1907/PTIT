#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
void Solve()
{
    int n;
    cin >> n;
    vector<pair<int, int>> a(n);
    for (auto &x : a)
        cin >> x.first >> x.second;
    sort(a.begin(), a.end());
    int cnt = 1, last = a[0].second;
    for (int i = 1; i < n; i++)
    {
        if (a[i].first >= last)
        {
            cnt++;
            last = a[i].second;
        }
        else if (a[i].second < last)
            last = a[i].second;
    }
    cout << cnt << "\n";
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
