#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
int main()
{
    int n, m;
    cin >> n >> m;
    int res = INT_MAX;
    if (n % 2 == 0 && m % 2 == 0)
        cout << "NO";
    else
    {
        res = min(res, (n & 1 ? 2 * n + 1 : INT_MAX));
        res = min(res, (m & 1 ? 2 * m + 1 : INT_MAX));
        cout << "YES  " << res;
    }
    return 0;
}
