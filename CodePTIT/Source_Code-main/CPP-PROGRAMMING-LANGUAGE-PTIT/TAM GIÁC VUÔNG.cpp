#include <bits/stdc++.h>
using namespace std;
#define ui64 unsigned long long
#define ll long long
bool isTriangle(ui64 a, ui64 b, ui64 c)
{
    if (a + b > c && b + c > a && a + c > b)
        return 1;
    return 0;
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        ui64 n, ok = 0;
        cin >> n;
        vector<ui64> a(n);
        for (int i = 0; i < n; i++)
            cin >> a[i];
        sort(a.begin(), a.end());
        for (ui64 i = 0; i < n; i++)
        {
            int ok1 = 0;
            for (ui64 j = i + 1; j < n; j++)
            {
                ui64 tg = a[i] * a[i] + a[j] * a[j];
                ui64 tmp = sqrt(tg);
                if (tg == tmp * tmp)
                {
                    if (binary_search(a.begin(), a.end(), (ui64)tmp))
                    {
                        ok1 = 1;
                        break;
                    }
                }
            }
            if (ok1)
            {
                ok = 1;
                break;
            }
        }
        cout << (ok ? "YES\n" : "NO\n");
    }
    return 0;
}