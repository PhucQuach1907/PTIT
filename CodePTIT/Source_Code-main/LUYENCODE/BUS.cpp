#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
int main()
{
    int n, d, t0;
    cin >> n >> d >> t0;
    vector<int> s(n);
    for (auto &x : s)
        cin >> x;
    int last = *max_element(s.begin(), s.end());
    vector<int> bus;
    for (int i = t0;; i += d)
    {
        bus.push_back(i);
        if (i > last)
            break;
    }
    vector<int> ans(n);
    for (int i = 0; i < n; i++)
    {
        auto pos = lower_bound(bus.begin(), bus.end(), s[i]) - bus.begin();
        ans[i] = pos + 1;
    }
    for (auto x : ans)
        cout << x << " ";
    return 0;
}
