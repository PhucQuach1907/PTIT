#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
int main()
{
    int n;
    cin >> n;
    vector<ll> a(n);
    for (auto &x : a)
        cin >> x;
    sort(a.begin(), a.end());
    int mid = n - n / 3;
    ll ans = 0;
    for (int i = 0; i < mid; i++)
        ans += a[i];
    cout << ans;
    return 0;
}
