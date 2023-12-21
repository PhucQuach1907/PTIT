#include <bits/stdc++.h>
using namespace std;
#define ui64 unsigned long long
#define ll long long
const ui64 P = 1e9 + 7;
ui64 nCk(ui64 n, ui64 k)
{
    ui64 C[k + 1];
    memset(C, 0, sizeof(C));
    C[0] = 1;
    for (ui64 i = 1; i <= n; i++)
    {
        for (ui64 j = min(i, k); j > 0; j--)
            C[j] = (C[j] + C[j - 1]) % P;
    }
    return C[k];
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        ui64 n, k;
        cin >> n >> k;
        cout << nCk(n, k) << "\n";
    }
    return 0;
}