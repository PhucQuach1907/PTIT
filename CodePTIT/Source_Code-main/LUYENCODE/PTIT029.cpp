#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
const ll MOD = 1e9 + 7;
int main()
{
    ll n;
    cin >> n;
    priority_queue<ll, vector<ll>, greater<ll>> pq;
    for (ll i = 0; i < n; i++)
    {
        ll x;
        cin >> x;
        pq.push(x);
    }
    ll ans = 0;
    while (pq.size() > 1)
    {
        ll m1 = pq.top();
        pq.pop();
        ll m2 = pq.top();
        pq.pop();
        ans += (m1 + m2);
        pq.push((m1 + m2));
    }
    cout << (ans % MOD);
    return 0;
}
