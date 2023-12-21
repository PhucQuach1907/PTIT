#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
int main()
{
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (auto &x : a)
        cin >> x;
    sort(a.begin(), a.end());
    int ans = 0;
    while (n > 0)
    {
        ans += 2 * (a[n - 1] - 1);
        n -= k;
    }
    cout << ans;
    return 0;
}
