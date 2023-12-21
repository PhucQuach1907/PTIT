#include <bits/stdc++.h>
using namespace std;
#define ui64 unsigned long long
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, maxx = INT_MIN;
        cin >> n;
        bool exist[n + 5];
        memset(exist, 0, sizeof(exist));
        vector<int> a(n);
        for (auto &c : a)
        {
            cin >> c;
            if (c > 0 && c <= n)
                exist[c] = 1;
        }
        for (int i = 1; i <= n + 1; i++)
        {
            if (!exist[i])
            {
                cout << i << "\n";
                break;
            }
        }
    }
    return 0;
}