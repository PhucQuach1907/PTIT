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
        vector<int> a(n);
        set<int> s;
        for (auto &c : a)
        {
            cin >> c;
            s.insert(c);
            maxx = max(maxx, c);
        }
        set<int>::iterator it;
        for (int i = 0; i < n; i++)
        {
            if (a[i] == maxx)
                cout << "_"
                     << " ";
            else
            {
                it = s.find(a[i]);
                it++;
                cout << *it << " ";
            }
        }
        cout << "\n";
    }
    return 0;
}