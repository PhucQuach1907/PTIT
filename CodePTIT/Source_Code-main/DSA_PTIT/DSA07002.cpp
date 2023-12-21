#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    stack<string> stk;
    int q;
    cin >> q;
    cin.ignore();
    while (q--)
    {
        string s;
        getline(cin, s);
        if (s[0] == 'P' && s[1] == 'U')
        {
            string tmp = "";
            for (int i = 5; i < (int)s.size(); i++)
                tmp += s[i];
            stk.push(tmp);
        }
        else if (s[0] == 'P' && s[1] == 'O')
        {
            if (!stk.empty())
                stk.pop();
        }
        else
            cout << (stk.empty() ? "NONE" : stk.top()) << "\n";
    }
    return 0;
}
