#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
void Solve()
{
    int n, m, pos;
    cin >> n >> m >> pos;
    pos--;
    multiset<int> ms;
    for (int i = 0; i < n + m; i++)
    {
        int x;
        cin >> x;
        ms.insert(x);
    }
    cout << *next(ms.begin(), pos) << "\n";
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
