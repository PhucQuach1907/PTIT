#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
int main()
{
    ll n;
    cin >> n;
    for (ll i = 0; i < 11; i++)
    {
        if (i * 111 <= n && (n - i * 111) % 11 == 0)
        {
            cout << "YES";
            return 0;
        }
    }
    cout << "NO";
    return 0;
}
/*
X = A * 11 + B * 111
Suppose B = C * 11 + D (D < 11)
X = (A + C * 111) * 11 + D * 111
*/
