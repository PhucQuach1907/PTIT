#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
int main()
{
    ll n;
    cin >> n;
    vector<ll> a(n);
    ll sum = 0;
    for (auto &x : a)
    {
        cin >> x;
        sum += x;
    }
    if (sum % 3 != 0)
    {
        cout << 0;
        return 0;
    }
    sum /= 3;
    vector<ll> last(n, 0);
    ll tmp = 0;
    for (ll i = n - 1; i >= 0; i--)
    {
        tmp += a[i];
        if (tmp == sum)
            last[i] = 1;
    }
    ll ans = 0;
    tmp = 0;
    for (ll i = n - 2; i >= 0; i--)
        last[i] += last[i + 1];
    for (ll i = 0; i < n - 2; i++)
    {
        tmp += a[i];
        if (tmp == sum)
            ans += last[i + 2];
    }
    cout << ans;
    return 0;
}
/*Ở bài này ta chỉ quan tâm đến tổng phần thứ nhất và phần thứ ba
