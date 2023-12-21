#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
int x;
bool cmp(pair<int, int> a, pair<int, int> b)
{
    if (abs(x - a.first) != abs(x - b.first))
        return (abs(x - a.first) < abs(x - b.first));
    return (a.second < b.second);
}
void Solve()
{
    int n;
    cin >> n >> x;
    vector<pair<int, int>> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i].first;
        a[i].second = i;
    }
    sort(a.begin(), a.end(), cmp);
    for (int i = 0; i < n; i++)
        cout << a[i].first << " \n"[i == n - 1];
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
