#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
ull Area(pair<ull, ull> d)
{
    return (d.first * d.second);
}
bool isValid(ull cur_area, pair<ull, ull> a, pair<ull, ull> b)
{
    ull x1 = a.first, y1 = a.second;
    ull x2 = b.first, y2 = b.second;
    if (x1 == x2)
    {
        if ((y1 + y2) * x1 == cur_area)
            return true;
    }
    if (x1 == y2)
    {
        if ((y1 + x2) * x1 == cur_area)
            return true;
    }
    if (y1 == x2)
    {
        if ((x1 + y2) * y1 == cur_area)
            return true;
    }
    if (y1 == y2)
    {
        if ((x1 + x2) * y1 == cur_area)
            return true;
    }
    return false;
}
int main()
{
    vector<pair<ull, ull>> a(3);
    cin >> a[0].first >> a[0].second >> a[1].first >> a[1].second >> a[2].first >> a[2].second;
    ull all = Area(a[0]) + Area(a[1]) + Area(a[2]);
    ull tmp = sqrt(all);
    if (tmp * tmp != all)
    {
        cout << 0;
        return 0;
    }
    bool ok = false;
    for (int i = 0; i < 3; i++)
    {
        if (i == 0)
            ok |= isValid(all - Area(a[0]), a[1], a[2]);
        else if (i == 1)
            ok |= isValid(all - Area(a[1]), a[0], a[2]);
        else
            ok |= isValid(all - Area(a[2]), a[0], a[1]);
    }
    cout << (ok ? tmp : 0);
    return 0;
}
