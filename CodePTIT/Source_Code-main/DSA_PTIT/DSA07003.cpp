#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
bool isOperator(char x)
{
    return (x == '+' || x == '-' || x == '*' || x == '/' || x == '^');
}
void Solve()
{
    string s;
    getline(cin, s);
    stack<char> stk;
    for (int i = 0; i < (int)s.size(); i++)
    {
        if (s[i] == ')')
        {
            int nmc = 0;
            while (!stk.empty() && stk.top() != '(')
            {
                nmc += isOperator(stk.top());
                stk.pop();
            }
            stk.pop();
            if (nmc == 0)
            {
                cout << "Yes\n";
                return;
            }
        }
        else
            stk.push(s[i]);
    }
    cout << "No\n";
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    cin.ignore();
    while (t--)
    {
        Solve();
    }
    return 0;
}
