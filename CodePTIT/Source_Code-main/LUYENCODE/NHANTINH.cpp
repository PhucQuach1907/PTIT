#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
const ll MAX = 1e5 + 5;
map<ll, vector<pair<ll, ll>>> key;
void Sieve()
{
    for (ll i = 1; i <= MAX / 2; i++)
    {
        for (ll j = i; j < MAX; j += i)
            key[j].push_back({i, j / i});
    }
}
int main()
{
    Sieve();
    ll n;
    cin >> n;
    ll a[n + 1];
    for (ll i = 1; i <= n; i++)
        cin >> a[i];
    for (ll i = 1; i <= n; i++)
    {
        for (auto x : key[i])
        {
            if (a[x.first] * a[x.second] != a[i])
            {
                cout << "NO";
                return 0;
            }
        }
    }
    cout << "YES";
    return 0;
}
