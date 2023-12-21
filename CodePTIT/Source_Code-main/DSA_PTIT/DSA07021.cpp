#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
void Solve()
{
    string s;
    cin >> s;
    stack<int> stk;
    int res = 0;
    stk.push(-1);
    for (int i = 0; i < (int)s.size(); i++)
    {
        if (s[i] == '(')
            stk.push(i);
        else
        {
            stk.pop();
            if (!stk.empty())
                res = max(res, i - stk.top());
            if (stk.empty())
                stk.push(i);
        }
    }
    cout << res << "\n";
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
