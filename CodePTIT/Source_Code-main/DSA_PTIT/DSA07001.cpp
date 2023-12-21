#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
void Show(stack<string> stk)
{
    if (stk.empty())
    {
        cout << "empty\n";
        return;
    }
    vector<string> a;
    while (!stk.empty())
    {
        a.push_back(stk.top());
        stk.pop();
    }
    for (int i = a.size() - 1; i >= 0; i--)
        cout << a[i] << " \n"[i == 0];
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    stack<string> stk;
    string s;
    while (getline(cin, s))
    {
        if (s[0] == 'p' && s[1] == 'u')
        {
            string tmp = "";
            for (int i = 5; i < (int)s.size(); i++)
                tmp += s[i];
            stk.push(tmp);
        }
        else if (s[0] == 's')
            Show(stk);
        else
            stk.pop();
    }
    return 0;
}
