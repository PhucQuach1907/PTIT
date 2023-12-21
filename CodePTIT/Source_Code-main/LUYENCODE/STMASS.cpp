#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
int to_Int(char c)
{
    return (c - '0');
}
int to_Number(string s)
{
    int num = 0;
    for (int i = 0; i < (int)s.size(); i++)
        num = num * 10 + to_Int(s[i]);
    return num;
}
int Weight(char c, char d)
{
    if (c == 'C')
        return 12 * to_Int(d);
    if (c == 'H')
        return to_Int(d);
    return 16 * to_Int(d);
}
string Format(string s)
{
    if (isalpha(s.back()))
        s.push_back('1');
    for (int i = 0; i < (int)s.size(); i++)
    {
        if (isalpha(s[i]) && !isdigit(s[i + 1]))
        {
            s.insert(i + 1, 1, '1');
            i--;
        }
    }
    if (s.back() == ')')
        s.push_back('1');
    for (int i = 0; i < (int)s.size(); i++)
    {
        if ((s[i] == ')' && s[i + 1] == '(') || (s[i] == ')' && s[i + 1] == ')'))
        {
            s.insert(i + 1, 1, '1');
            i--;
        }
    }
    return s;
}
void Solve()
{
    string s;
    cin >> s;
    s = Format(s);
    int n = s.size();
    stack<string> stk;
    int i = 0;
    while (i < n)
    {
        if (s[i] == '(')
        {
            string tmp(1, s[i]);
            stk.push(tmp);
            i++;
            continue;
        }
        if (isalpha(s[i]))
        {
            string w = to_string(Weight(s[i], s[i + 1]));
            stk.push(w);
            i += 2;
        }
        else if (s[i] == ')')
        {
            int mid = 0;
            while (!stk.empty() && stk.top() != "(")
            {
                mid += to_Number(stk.top());
                stk.pop();
            }
            stk.pop();
            stk.push(to_string(mid * to_Int(s[i + 1])));
            i += 2;
        }
    }
    int ans = 0;
    while (!stk.empty())
    {
        ans += to_Number(stk.top());
        stk.pop();
    }
    cout << ans << "\n";
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
