#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
int main()
{
    int n, m;
    cin >> n >> m;
    vector<int> a(n), b(m);
    for (auto &x : a)
        cin >> x;
    for (auto &x : b)
        cin >> x;
    for (auto x : b)
    {
        auto pos = lower_bound(a.begin(), a.end(), x);
        cout << (*pos == x ? pos - a.begin() + 1 : 0) << " ";
    }
    return 0;
}
