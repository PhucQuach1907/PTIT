#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
void Solve()
{
    int n;
    cin >> n;
    int zero = 0;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        zero += (x == 0);
    }
    cout << zero << "\n";
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
