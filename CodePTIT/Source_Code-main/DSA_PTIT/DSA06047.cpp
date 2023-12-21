#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
void Solve()
{
    ll n;
    scanf("%lld", &n);
    vector<ll> a(n);
    unordered_map<ll, ll> cnt;
    for (ll i = 0; i < n; i++)
    {
        scanf("%lld", &a[i]);
        cnt[a[i]]++;
    }
    for (ll i = 0; i < n - 1; i++)
    {
        for (ll j = i + 1; j < n; j++)
        {
            ll c = sqrt(a[i] * a[i] + a[j] * a[j]);
            if (a[i] * a[i] + a[j] * a[j] == c * c && cnt[c] > 0)
            {
                printf("YES\n");
                return;
            }
        }
    }
    printf("NO\n");
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    scanf("%d", &t);
    while (t--)
    {
        Solve();
    }
    return 0;
}
