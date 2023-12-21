#include <bits/stdc++.h>
using namespace std;
#define ui64 unsigned long long
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, d;
        cin >> n >> d;
        vector<int> a(n);
        for (auto &c : a)
            cin >> c;
        for (int i = d; i < n; i++)
            cout << a[i] << " ";
        for (int i = 0; i < d; i++)
            cout << a[i] << " ";
        cout << "\n";
    }
    return 0;
}