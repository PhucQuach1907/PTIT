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
    sort(a.begin(), a.end());
    cout << max({a[0] * a[1], a[n - 1] * a[n - 2], a[0] * a[1] * a[n - 1], a[n - 1] * a[n - 2] * a[n - 3]});
    return 0;
}
