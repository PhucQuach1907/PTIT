#include <bits/stdc++.h>
using namespace std;
#define ui64 unsigned long long
#define ll long long
ui64 a[21];
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        ui64 n, m, big, a, b, sum;
        cin >> n >> m;
        sum = (n * (n + 1)) / 2;
        a = (sum + m) / 2;
        b = sum - a;
        if (sum < m)
            cout << "No\n";
        else if (a + b == sum && a - b == m)
        {
            cout << (__gcd(a, b) == 1 ? "Yes\n" : "No\n");
        }
        else
            cout << "No\n";
    }
    return 0;
}