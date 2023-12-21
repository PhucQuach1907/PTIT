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
        int n, zero = 0;
        cin >> n;
        vector<int> a(n);
        for (auto &c : a)
            cin >> c;
        for (int i = 0; i < n - 1; i++)
        {
            if (a[i + 1] && a[i] == a[i + 1])
            {
                a[i] *= 2;
                a[i + 1] = 0;
            }
        }
        for (int i = 0; i < n; i++)
        {
            if (a[i])
                cout << a[i] << " ";
            else
                zero++;
        }
        for (int i = 1; i <= zero; i++)
            cout << 0 << " ";
        cout << "\n";
    }
    return 0;
}