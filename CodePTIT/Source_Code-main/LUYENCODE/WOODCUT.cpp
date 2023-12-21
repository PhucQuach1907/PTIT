#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
int main()
{
    ll n, ans = 0;
    cin >> n;
    priority_queue<ll, vector<ll>, greater<ll>> pq;
    for (ll i = 0; i < n; i++)
    {
        ll x;
        cin >> x;
        pq.push(x);
    }
    while (pq.size() > 1)
    {
        ll m1 = pq.top(), m2;
        pq.pop();
        if (!pq.empty())
        {
            m2 = pq.top();
            pq.pop();
        }
        else
            m2 = 0;
        ans += (m1 + m2);
        pq.push(m1 + m2);
    }
    cout << ans;
    return 0;
}
