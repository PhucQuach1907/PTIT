#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
void Solve()
{
    string s;
    cin >> s;
    int n = s.size(), res = 1, len, l, r;
    for (int i = 0; i < n; i++)
    {
        len = 1, l = i - 1, r = i + 1;
        while (s[l] == s[r] && l >= 0 && r < n)
        {
            len += 2;
            l--, r++;
        }
        res = max(res, len);
        len = 0, l = i, r = i + 1;
        while (s[l] == s[r] && l >= 0 && r < n)
        {
            len += 2;
            l--, r++;
        }
        res = max(res, len);
    }
    cout << res << "\n";
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        Solve();
    }
    return 0;
}
