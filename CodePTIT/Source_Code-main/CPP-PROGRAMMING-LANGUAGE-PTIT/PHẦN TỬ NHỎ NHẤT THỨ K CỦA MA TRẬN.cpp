#include <bits/stdc++.h>
using namespace std;
#define ui64 unsigned long long
const double PI = 2 * acos(0);
const int MOD = 1e9 + 7;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, k, x;
        cin >> n >> k;
        vector<int> a;
        for (int i = 1; i <= n * n; i++)
        {
            cin >> x;
            a.push_back(x);
        }
        sort(a.begin(), a.end());
        cout << a[k - 1] << "\n";
    }
    return 0;
}