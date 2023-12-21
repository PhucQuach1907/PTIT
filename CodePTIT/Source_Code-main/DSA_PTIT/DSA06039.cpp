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
    for (int i = 0; i < n; i++)
    {
        if (cnt[a[i]] > 1)
        {
            cout << a[i] << "\n";
            return;
        }
    }
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
