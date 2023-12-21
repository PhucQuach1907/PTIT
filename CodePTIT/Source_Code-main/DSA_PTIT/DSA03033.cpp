#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
int main()
{
    vector<vector<ll>> v;
    for (ll i = 0; i < 16; i++)
    {
        vector<ll> tmp;
        for (auto x : {1000, 2000, 3000, 5000})
            tmp.push_back(x * pow(10, i));
        v.push_back(tmp);
    }

    int t;
    cin >> t;
    while (t--)
    {
        ll n, c;
        cin >> n >> c;
        if (n % 1000 != 0)
        {
            cout << 0 << "\n";
            continue;
        }
        map<ll, ll> cnt;
        ll ans1 = 0, ans2 = 1;
        for (ll i = c; i >= 0; i--)
        {
            for (ll j = 3; j >= 0; j--)
            {
                if (n >= v[i][j])
                {
                    ll d = n / v[i][j];
                    cnt[v[i][j]] = d;
                    ans1 += d;
                    n -= (d * v[i][j]);
                }
            }
        }
        for (ll i = 0; i < 16; i++)
        {
            ll q = 1;
            bool one = false, three = false, five = false;
            for (ll j = 0; j < 4; j++)
            {
                if (j == 0 && cnt[v[i][j]] > 0)
                    one = true;
                if (j == 2 && cnt[v[i][j]] > 0)
                    three = true;
                if (j == 3 && cnt[v[i][j]] > 0)
                    five = true;
            }
            if (one == true && three == true && five == true)
                q = 3;
            else if (one == true && (three == true || five == true))
                q = 2;
            ans2 *= q;
        }
        cout << ans1 << " " << ans2 << "\n";
    }
    return 0;
}
