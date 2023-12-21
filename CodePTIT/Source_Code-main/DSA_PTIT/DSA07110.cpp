#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
bool Check(string s)
{
    stack<char> q;
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == '(' || s[i] == '[' || s[i] == '{')
            q.push(s[i]);
        else
        {
            if (q.empty())
                return false;
            char c = q.top();
            if ((c == '(' && s[i] != ')') || (c == '[' && s[i] != ']') || (c == '{' && s[i] != '}'))
                return false;
            q.pop();
        }
    }
    if (!q.empty())
        return false;
    return true;
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string s;
        cin >> s;
        cout << (Check(s) ? "YES\n" : "NO\n");
    }
    return 0;
}
