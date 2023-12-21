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
            string n2 = stk.top();
            stk.pop();
            string n1 = stk.top();
            stk.pop();
            string tmp = n1 + s[i] + n2;
            stk.push(tmp);
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
