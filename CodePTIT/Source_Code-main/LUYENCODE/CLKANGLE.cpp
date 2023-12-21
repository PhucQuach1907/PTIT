#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
int main()
{
    int h, m;
    cin >> h >> m;
    double ans = abs((60 * h + m) * 1.0 / 2 - 6 * m);
    ans = (ans >= 180 ? 360 - ans : ans);
    cout << fixed << setprecision(1) << ans;
    return 0;
}
