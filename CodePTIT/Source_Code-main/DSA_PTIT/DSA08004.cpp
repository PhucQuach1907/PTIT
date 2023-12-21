#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
void Solve()
{
    ll k;
    string s;
    cin >> k >> s;
    unordered_map<char, ll> cnt;
    for (auto x : s)
        cnt[x]++;
    priority_queue<ll> pq;
    for (auto x : cnt)
        pq.push(x.second);
    ll res = 0;
    while (k--)
    {
        ll cur = pq.top();
        pq.pop();
        if (cur == 0)
            break;
        pq.push(--cur);
    }
    while (!pq.empty())
    {
        ll cur = pq.top();
        pq.pop();
        res += (cur * cur);
    }
    cout << res << "\n";
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        Solve();
    }
    return 0;
}
