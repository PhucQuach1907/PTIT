#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
char c;
bool CanDelete(string s)
{
    sort(s.begin(), s.end());
    return (binary_search(s.begin(), s.end(), c));
}
int main()
{
    int n, q;
    cin >> n >> q;
    vector<int> vis(26, false);
    vector<string> a(n);
    for (auto &x : a)
        cin >> x;
    while (q--)
    {
        cin >> c;
        if (vis[c - 'a'])
        {
            cout << a.size() << "\n";
            continue;
        }
        a.erase(remove_if(a.begin(), a.end(), CanDelete), a.end());
        vis[c - 'a'] = true;
        cout << a.size() << "\n";
    }
    return 0;
}
