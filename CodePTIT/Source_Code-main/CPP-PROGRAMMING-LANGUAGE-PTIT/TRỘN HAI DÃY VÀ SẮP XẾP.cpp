#include <bits/stdc++.h>
using namespace std;
#define ui64 unsigned long long
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m, x;
        cin >> n >> m;
        vector<int> a;
        for (int i = 1; i <= m + n; i++)
        {
            cin >> x;
            a.push_back(x);
        }
        sort(a.begin(), a.end());
        for (int i = 0; i < a.size(); i++)
            cout << a[i] << " ";
        cout << "\n";
    }
    return 0;
}
