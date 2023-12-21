#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
void Solve()
{
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (auto &x : a)
        cin >> x;
    auto pos = lower_bound(a.begin(), a.end(), k);
    if (pos == a.end())
        cout << "NO\n";
    else
    {
        int p = pos - a.begin();
        cout << (a[p] == k ? to_string(p + 1) : "NO") << "\n";
    }
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
