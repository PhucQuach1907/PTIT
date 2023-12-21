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
    sort(a.rbegin(), a.rend());
    int mid = (n + 1) / 2;
    int l = 0, r = mid, p = 0;
    while (l < mid && r < n)
    {
        if (a[l] >= 2 * a[r])
        {
            p++;
            l++, r++;
        }
        else
            r++;
    }
    cout << (n - p) << "\n";
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
