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
    vector<int> l(n), r(n);
    l[0] = 0;
    for (int i = 1; i < n; i++)
        l[i] = (a[i] > a[i - 1] ? l[i - 1] + 1 : 0);
    r[n - 1] = 0;
    for (int i = n - 2; i >= 0; i--)
        r[i] = (a[i] > a[i + 1] ? r[i + 1] + 1 : 0);
    for (int i = 0; i < n; i++)
        cout << (l[i] + r[i] + 1) << " ";
    return 0;
}
