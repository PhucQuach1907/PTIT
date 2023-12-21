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
    int mn = *min_element(a.begin(), a.end());
    for (int i = 0; i < n; i++)
    {
        if (a[i] == mn)
        {
            cout << i << "\n";
            return;
        }
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
