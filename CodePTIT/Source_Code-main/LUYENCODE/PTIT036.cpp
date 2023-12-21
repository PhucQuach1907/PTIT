#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
int main()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &x : a)
        cin >> x;
    int m;
    cin >> m;
    vector<int> b(m);
    for (auto &x : b)
        cin >> x;
    int p = 0;
    for (int i = 0; i < m; i++)
    {
        auto pos = lower_bound(a.begin(), a.end(), b[i]);
        p += (pos == a.end() || *pos != b[i] ? -1 : pos - a.begin() + 1);
    }
    p %= 30;
    cout << (int)(pow(2, p));
    return 0;
}
