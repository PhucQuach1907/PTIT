#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll n, t;
    cin >> n >> t;
    ll sum = 0;
    int ans = 0;
    priority_queue<ll> q;
    for (ll i = 0; i < n; i++)
    {
        ll xi, ti;
        cin >> xi >> ti;
        sum += ti;
        q.push(ti);
        while (!q.empty() && sum + xi > t)
        {
            sum -= q.top();
            q.pop();
        }
        ans = max(ans, (int)q.size());
    }
    cout << ans;
    return 0;
}
