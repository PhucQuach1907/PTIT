#include <bits/stdc++.h>
using namespace std;
#define ui64 unsigned long long
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        vector<int> a(n);
        for (auto &c : a)
            cin >> c;
        sort(a.begin(), a.end());
        cout << a[k - 1] << "\n";
    }
    return 0;
}