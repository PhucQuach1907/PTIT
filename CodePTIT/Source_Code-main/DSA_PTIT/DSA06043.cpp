#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
void Solve()
{
    int n;
    cin >> n;
    vector<int> a(n), pref(n);
    for (auto &x : a)
        cin >> x;
    int sum = accumulate(a.begin(), a.end(), 0);
    pref[0] = a[0];
    for (int i = 1; i < n; i++)
        pref[i] = pref[i - 1] + a[i];
    for (int i = 1; i < n - 1; i++)
    {
        if (sum - a[i] - pref[i - 1] == pref[i - 1])
        {
            cout << i + 1 << "\n";
            return;
        }
    }
    cout << "-1\n";
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
