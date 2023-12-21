#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
int main()
{
    ll n;
    cin >> n;
    ll sum = 0;
    for (ll i = 0; i < n; i++)
    {
        ll x;
        cin >> x;
        sum += (x > 0 ? x : 0);
    }
    cout << sum * 2;
    return 0;
}
