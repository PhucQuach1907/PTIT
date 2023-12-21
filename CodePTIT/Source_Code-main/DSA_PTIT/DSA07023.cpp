#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
void Solve()
{
    string s;
    getline(cin, s);
    char *str = new char[s.size() + 1];
    strcpy(str, s.c_str());
    stack<string> stk;
    char *p = strtok(str, " \t\n");
    while (p != NULL)
    {
        stk.push(p);
        p = strtok(NULL, " \t\n");
    }
    while (!stk.empty())
    {
        cout << stk.top() << " ";
        stk.pop();
    }
    cout << "\n";
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
