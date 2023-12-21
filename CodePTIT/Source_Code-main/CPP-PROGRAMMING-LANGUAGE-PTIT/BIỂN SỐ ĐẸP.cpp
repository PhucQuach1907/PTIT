#include <bits/stdc++.h>
using namespace std;
#define ui64 unsigned long long
#define ll long long
bool isBeautiful(string s)
{
    return (((s[0] < s[1] && s[1] < s[2] && s[2] < s[3] && s[3] < s[4]) || (s[0] == s[1] && s[1] == s[2] && s[2] == s[3] && s[3] == s[4]) || (s[0] == s[1] && s[1] == s[2] && s[3] == s[4]) || ((s[0] == '6' || s[0] == '8') && (s[1] == '6' || s[1] == '8') && (s[2] == '6' || s[2] == '8') && (s[3] == '6' || s[3] == '8') && (s[4] == '6' || s[4] == '8'))) ? 1 : 0);
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string s, num;
        cin >> s;
        num = s.substr(5, 6);
        num.erase(3, 1);
        cout << (isBeautiful(num) ? "YES\n" : "NO\n");
    }
    return 0;
}