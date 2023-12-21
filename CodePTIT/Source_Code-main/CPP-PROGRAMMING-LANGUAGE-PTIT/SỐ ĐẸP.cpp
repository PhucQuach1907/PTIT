#include <bits/stdc++.h>
using namespace std;
#define ui64 unsigned long long
#define ll long long
bool isEvenString(string s)
{
    for (int i = 0; i < s.size(); i++)
    {
        if ((s[i] - '0') % 2)
            return 0;
    }
    return 1;
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string s, tg;
        cin >> s;
        tg = s;
        reverse(s.begin(), s.end());
        cout << (tg == s && isEvenString(tg) ? "YES\n" : "NO\n");
    }
    return 0;
}