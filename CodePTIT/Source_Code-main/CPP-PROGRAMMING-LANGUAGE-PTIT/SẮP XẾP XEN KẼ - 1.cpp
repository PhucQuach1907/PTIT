#include <bits/stdc++.h>
using namespace std;
#define ui64 unsigned long long
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> a(n);
        for (auto &c : a)
            cin >> c;
        sort(a.begin(), a.end());
        int l = 0, r = n - 1;
        for (int i = 0; i < n; i++)
            cout << (i % 2 ? a[l++] : a[r--]) << " ";
        cout << "\n";
    }
    return 0;
}