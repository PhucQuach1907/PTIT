#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
void Solve()
{
    string s;
    cin >> s;
    stack<int> stk;
    int n = s.size();
    for (int i = 0; i <= n; i++)
    {
        if (s[i] == 'D')
            stk.push(i + 1);
        else if (s[i] == 'I' || i == n)
        {
            stk.push(i + 1);
            while (!stk.empty())
            {
                cout << stk.top();
                stk.pop();
            }
        }
    }
    cout << "\n";
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
