#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
bool cmp(int a, int b)
{
    return (abs(a) < abs(b));
}
int main()
{
    int n, t;
    cin >> t >> n;
    vector<int> pos(n);
    for (auto &x : pos)
        cin >> x;
    sort(pos.begin(), pos.end(), cmp);
    int cur = 0, sum = 0, i = 0, ans = 0;
    while (sum + abs(pos[i] - cur) <= t && i < n)
    {
        sum += abs(pos[i] - cur);
        cur = pos[i];
        i++;
        ans++;
    }
    cout << ans;
    return 0;
}
