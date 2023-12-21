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
    vector<int> pos;
    pos.push_back(-1);
    for (int i = 0; i < n; i++)
    {
        if (a[i] & 1)
            pos.push_back(i);
    }
    pos.push_back(n);
    ll ans = 0;
    int len = pos.size();
    for (int i = 0; i < len - k - 1; i++)
    {
        ll l1 = pos[i] + 1, r1 = pos[i + 1];
        ll l2 = pos[i + k], r2 = pos[i + k + 1] - 1;
        ans += ((r1 - l1 + 1) * (r2 - l2 + 1));
    }
    cout << ans;
    return 0;
}
