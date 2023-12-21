#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
int main()
{
    int m, n, k;
    cin >> m >> n >> k;
    int ans = min(m / 2, n);
    int remain = m + n - 3 * ans;
    int need = max(0, k - remain);
    ans -= ceil(need * 1.0 / 3);
    cout << ans;
    return 0;
}
