#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
void Solve()
{
    string s;
    cin >> s;
    stack<string> stk;
    for (int i = 0; i < (int)s.size(); i++)
    {
        if (isalpha(s[i]))
        {
            string tmp(1, s[i]);
            stk.push(tmp);
        }
        else
        {
            string a = stk.top();
            stk.pop();
            string b = stk.top();
            stk.pop();
            stk.push("(" + b + s[i] + a + ")");
        }
    }
    cout << stk.top() << "\n";
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
