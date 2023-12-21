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
            string tmp(1, s[i]);
            q.push(tmp);
        }
        else
        {
            string tmp(1, s[i]);
            string s1 = q.top();
            q.pop();
            string s2 = q.top();
            q.pop();
            string tmp1 = s1 + s2 + tmp;
            q.push(tmp1);
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
