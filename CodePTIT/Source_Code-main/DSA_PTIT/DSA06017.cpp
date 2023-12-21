#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
void Solve()
{
    int n, m;
    cin >> n >> m;
    vector<int> a;
    for (int i = 0; i < n + m; i++)
    {
        int x;
        cin >> x;
        a.push_back(x);
    }
    sort(a.begin(), a.end());
    for (int i = 0; i < m + n; i++)
        cout << a[i] << " \n"[i == m + n - 1];
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
