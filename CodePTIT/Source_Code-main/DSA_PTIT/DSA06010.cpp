#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
void Solve()
{
    int n;
    cin >> n;
    vector<string> a(n);
    for (auto &x : a)
        cin >> x;
    set<char> s;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < a[i].size(); j++)
            s.insert(a[i][j]);
    }
    for (auto x : s)
        cout << x << " ";
    cout << "\n";
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
