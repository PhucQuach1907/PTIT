#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
int main()
{
    string s;
    cin >> s;
    stack<int> stk;
    for (int i = 0; i < (int)s.size(); i++)
    {
        if (s[i] == '(')
            stk.push(i + 1);
        else
        {
            cout << stk.top() << " " << i + 1 << "\n";
            stk.pop();
        }
    }
    return 0;
}
