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
        int n, q, sum = 0, l, r;
        cin >> n >> q;
        vector<int> prefix;
        prefix.push_back(0);
        for (int i = 0; i < n; i++)
        {
            int x;
            cin >> x;
            prefix.push_back(sum += x);
        }
        while (q--)
        {
            cin >> l >> r;
            cout << prefix[r] - prefix[l - 1] << "\n";
        }
    }
    return 0;
}