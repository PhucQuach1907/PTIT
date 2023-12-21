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
        vector<string> a(n);
        set<int> s;
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
            for (int j = 0; j < a[i].size(); j++)
                s.insert(a[i][j] - '0');
        }
        for (int x : s)
            cout << x << " ";
        cout << "\n";
    }
    return 0;
}