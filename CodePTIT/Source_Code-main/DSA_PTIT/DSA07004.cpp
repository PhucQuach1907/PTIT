#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
void Solve()
{
    string s;
    cin >> s;
    int res = 0;
    res += (s[0] == ')' ? 1 : 0);
    res += (s[s.size() - 1] == '(' ? 1 : 0);
    s[0] = '(', s[s.size() - 1] = ')';
    int close = 0;
    stack<char> q;
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == '(')
            q.push(s[i]);
        else
        {
            if (!q.empty())
                q.pop();
            else
            {
                res++;
                q.push('(');
            }
        }
    }
    res += (q.size() / 2);
    cout << res << "\n";
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
