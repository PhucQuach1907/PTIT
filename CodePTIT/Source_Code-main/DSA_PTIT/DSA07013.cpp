#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
int Calc(int a, int b, char x)
{
    if (x == '+')
        return a + b;
    else if (x == '-')
        return a - b;
    else if (x == '*')
        return a * b;
    return a / b;
}
void Solve()
{
    string s;
    cin >> s;
    stack<int> stk;
    for (int i = 0; i < (int)s.size(); i++)
    {
        if (isdigit(s[i]))
            stk.push(s[i] - '0');
        else
        {
            int m2 = stk.top();
            stk.pop();
            int m1 = stk.top();
            stk.pop();
            stk.push(Calc(m1, m2, s[i]));
        }
    }
    cout << stk.top() << "\n";
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--)
    {
        Solve();
    }
    return 0;
}
