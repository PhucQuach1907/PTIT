#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
void Solve()
{
    string s;
    cin >> s;
    stack<int> stk;
    int ans = 0;
    for (int i = 0; i < (int)s.size(); i++)
    {
        if (s[i] == '(')
            stk.push(i);
        else
        {
            if (!stk.empty())
            {
                ans++;
                stk.pop();
            }
        }
    }
    cout << ans * 2 << "\n";
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
