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
        int a[n][n];
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
                cin >> a[i][j];
        }
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
                cout << (i == 0 || j == 0 || i == n - 1 || j == n - 1 ? to_string(a[i][j]) : " ") << " ";
            cout << "\n";
        }
    }
    return 0;
}