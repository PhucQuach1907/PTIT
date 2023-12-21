#include <bits/stdc++.h>
using namespace std;
#define ui64 unsigned long long
#define ll long long
bool isValid(string s)
{
    for (int i = 0; i < s.size(); i++)
    {
        if (s[0] == '0' || s[i] < '0' || s[i] > '9')
            return 0;
    }
    return 1;
}
bool isFullNumber(string s)
{
    set<char> a;
    for (int i = 0; i < s.size(); i++)
        a.insert(s[i]);
    return (a.size() == 10);
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string s;
        cin >> s;
        if (!isValid(s))
            cout << "INVALID\n";
        else
            cout << (isFullNumber(s) ? "YES\n" : "NO\n");
    }
    return 0;
}