#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
int main()
{
    string s;
    cin >> s;
    stack<char> stk, tmp;
    for (int i = 0; i < (int)s.size(); i++)
    {
        if (s[i] == '<')
        {
            if (!stk.empty())
            {
                tmp.push(stk.top());
                stk.pop();
            }
        }
        else if (s[i] == '>')
        {
            if (!tmp.empty())
            {
                stk.push(tmp.top());
                tmp.pop();
            }
        }
        else if (s[i] == '-')
        {
            if (!stk.empty())
                stk.pop();
        }
        else
            stk.push(s[i]);
    }
    while (!tmp.empty())
    {
        stk.push(tmp.top());
        tmp.pop();
    }
    string ans = "";
    while (!stk.empty())
    {
        ans += stk.top();
        stk.pop();
    }
    for (int i = (int)ans.size() - 1; i >= 0; i--)
        cout << ans[i];
    return 0;
}
