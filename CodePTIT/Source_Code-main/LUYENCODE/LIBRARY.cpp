#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
const ll MAX = 1e5 + 5;
vector<ll> adj[MAX];
bool vis[MAX];
vector<ll> v;
ll cost[MAX];
void DFS(ll i)
{
    v.push_back(cost[i]);
    vis[i] = true;
    for (auto x : adj[i])
    {
        if (!vis[x])
            DFS(x);
    }
}
int main()
{
    ll n, m;
    cin >> n >> m;
    for (ll i = 1; i <= n; i++)
        cin >> cost[i];
    for (ll i = 0; i < m; i++)
    {
        ll x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    memset(vis, false, sizeof(vis));
    ll ans = 0;
    for (ll i = 1; i <= n; i++)
    {
        if (!vis[i])
        {
            DFS(i);
            ans += *min_element(v.begin(), v.end());
            v.clear();
        }
    }
    cout << ans;
    return 0;
}
