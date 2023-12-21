#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
int main()
{
    int k, n, a, b, c;
    cin >> k >> n >> a >> b >> c;
    if (k == 2)
        cout << min({a, b, c});
    else
        cout << max(0, min({c - (2 * n - a - b), a - (2 * n - b - c), c - (2 * n - a - b)}));
    return 0;
}
