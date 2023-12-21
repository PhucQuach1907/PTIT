#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
const ll NMC = 101;
const ll MOD = 1e9 + 7;
const ll MAX = 1e5 + 5;
ll BIT_Pref[MAX];
ll BIT_Suff[MAX];
ll pw[MAX];
string s;
ll n;
void Update(ll BIT[], ll idx, ll old_val, ll new_val)
{
    while (idx <= n)
    {
        BIT[idx] = (BIT[idx] - old_val + MOD) % MOD;
        BIT[idx] = (BIT[idx] + new_val) % MOD;
        idx += idx & (-idx);
    }
}
ll getSum(ll BIT[], ll idx)
{
    ll sum = 0;
    while (idx > 0)
    {
        sum = (sum + BIT[idx]) % MOD;
        idx -= idx & (-idx);
    }
    return sum;
}
ll getSumRange(ll BIT[], ll l, ll r)
{
    return (getSum(BIT, r) - getSum(BIT, l - 1) + MOD) % MOD;
}
ll Pow(ll a, ll b)
{
    ll res = 1;
    while (b)
    {
        if (b & 1)
            res = (res * a) % MOD;
        a = (a * a) % MOD;
        b >>= 1;
    }
    return res;
}
ll divMod(ll t, ll m)
{
    t %= MOD;
    ll res = (t * Pow(m, MOD - 2)) % MOD;
    return res;
}
bool isPalindrome(ll l, ll r)
{
    while (r > l)
    {
        if (s[l++] != s[r--])
            return false;
    }
    return true;
}
void init()
{
    pw[0] = 1;
    for (ll i = 1; i < MAX; i++)
        pw[i] = (pw[i - 1] * NMC) % MOD;
    for (ll i = 0; i < MAX; i++)
        BIT_Pref[i] = BIT_Suff[i] = 0;
    for (ll i = 1; i <= n; i++)
        Update(BIT_Pref, i, 0, (s[i] * pw[i - 1]) % MOD);
    string rev(s.begin() + 1, s.end());
    reverse(rev.begin(), rev.end());
    rev = "-" + rev;
    for (ll i = 1; i <= n; i++)
        Update(BIT_Suff, i, 0, (rev[i] * pw[i - 1]) % MOD);
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> s;
    n = s.size();
    s = "-" + s;
    init();
    ll q;
    cin >> q;
    while (q--)
    {
        char x;
        ll c1, c2;
        cin >> c1 >> c2;
        ll tmp1 = divMod(getSumRange(BIT_Pref, c1, c2), pw[c1 - 1]);
        ll tmp2 = divMod(getSumRange(BIT_Suff, n - c2 + 1, n - c1 + 1), pw[n - c2]);
        if (tmp1 == tmp2)
            cout << (isPalindrome(c1, c2) ? "YES\n" : "NO\n");
        else
            cout << "NO\n";
    }
    return 0;
}
