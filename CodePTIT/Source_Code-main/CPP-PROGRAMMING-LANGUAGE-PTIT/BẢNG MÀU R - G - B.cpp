#include <bits/stdc++.h>
using namespace std;
#define ui64 unsigned long long
#define ll long long
ui64 a[21];
int main()
{
    a[0] = 1;
    for (ui64 i = 1; i <= 20; i++)
        a[i] = a[i - 1] * i;
    ui64 t;
    cin >> t;
    while (t--)
    {
        ui64 n, r, b, g, shortage, ans = 0;
        cin >> n >> r >> b >> g;
        shortage = n - (r + b + g);
        for (ui64 i = 0; i <= shortage; i++)
        {
            for (ui64 j = 0; j <= shortage - i; j++)
                ans += a[n] / (a[i + r] * a[j + g] * a[b + shortage - i - j]);
        }
        cout << ans << "\n";
    }
    return 0;
}