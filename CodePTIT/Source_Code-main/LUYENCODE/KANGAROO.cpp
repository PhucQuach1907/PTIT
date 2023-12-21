#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
void Solve()
{
    int xA, vA, xB, vB;
    cin >> xA >> vA >> xB >> vB;
    int x = (xB - xA) / (vA - vB);
    cout << (x >= 0 && x * (vA - vB) == xB - xA ? "YES\n" : "NO\n");
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        Solve();
    }
    return 0;
}
