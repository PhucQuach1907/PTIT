#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
struct Data
{
    int s, e;
};
bool cmp(Data a, Data b)
{
    return (a.s < b.s);
}
int main()
{
    int n;
    cin >> n;
    vector<Data> a(n);
    for (auto &x : a)
        cin >> x.s >> x.e;
    sort(a.begin(), a.end(), cmp);
    int ans = 1, end = a[0].e;
    for (int i = 1; i < n; i++)
    {
        if (a[i].s >= end)
        {
            ans++;
            end = a[i].e;
        }
        else if (a[i].e < end)
            end = a[i].e;
    }
    cout << ans;
    return 0;
}
