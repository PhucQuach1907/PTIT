#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
int main()
{
    stack<int> stk;
    int t;
    cin >> t;
    while (t--)
    {
        int type;
        cin >> type;
        if (type == 1)
        {
            int n;
            cin >> n;
            stk.push(n);
        }
        else if (type == 2)
        {
            if (!stk.empty())
                stk.pop();
        }
        else
            cout << (stk.empty() ? "Empty!" : to_string(stk.top())) << "\n";
    }
    return 0;
}
