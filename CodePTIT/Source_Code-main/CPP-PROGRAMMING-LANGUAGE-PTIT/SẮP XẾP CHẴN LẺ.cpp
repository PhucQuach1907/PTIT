#include <bits/stdc++.h>
using namespace std;
#define ui64 unsigned long long
#define ll long long
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
        int l = 0, r = (n & 1 ? n / 2 + 1 : n / 2);
        for (int i = 1; i <= n; i++)
            cout << (i & 1 ? a[l++] : a[r++]) << " ";
        cout << "\n";
    }
    return 0;
}