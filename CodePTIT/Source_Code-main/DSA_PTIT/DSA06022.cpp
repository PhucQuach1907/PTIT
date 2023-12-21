#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> a(n);
        set<int> s;
        for (auto &c : a)
        {
            cin >> c;
            s.insert(c);
        }
        set<int>::iterator it = s.begin();
        if (s.size() == 1)
            cout << -1 << "\n";
        else
        {
            cout << *it << " ";
            advance(it, 1);
            cout << *it << "\n";
        }
    }
    return 0;
}
