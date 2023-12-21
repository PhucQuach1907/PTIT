#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int W, H, n;
    cin >> W >> H >> n;
    int lx = 0, rx = W, ty = H, by = 0;
    for (int i = 0; i < n; i++)
    {
        int xi, yi, type;
        cin >> xi >> yi >> type;
        if (type == 1)
            lx = max(lx, xi);
        else if (type == 2)
            rx = min(rx, xi);
        else if (type == 3)
            by = max(by, yi);
        else
            ty = min(ty, yi);
    }
    cout << (rx - lx) * (ty - by);
    return 0;
}
