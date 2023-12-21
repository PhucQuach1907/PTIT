#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
void Solve()
{
    string s;
    cin >> s;
    stack<string> q;
    for (int i = s.size() - 1; i >= 0; i--)
    {
        if (isalpha(s[i]))
        {
            string tmp = "";
            tmp += s[i];
            q.push(tmp);
        }
        else
        {
            string sign = "";
            sign += s[i];
            string s1 = q.top();
            q.pop();
            string s2 = q.top();
            q.pop();
            string tmp = "(" + s1 + sign + s2 + ")";
            q.push(tmp);
        }
    }
    cout << q.top() << "\n";
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
