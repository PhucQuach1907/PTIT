#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
void Solve()
{
    int n, x;
    cin >> n >> x;
    vector<int> a(n);
    for (auto &x : a)
        cin >> x;
    cout << (binary_search(a.begin(), a.end(), x) ? 1 : -1) << "\n";
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
