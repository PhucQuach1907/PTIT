#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
bool isOperator(char c)
{
    return (c != '+' && c != '-' && c != '*' && c != '/' && c != '%' && c != '^' ? false : true);
}
void Solve()
{
    map<char, int> pri;
    pri['+'] = pri['-'] = 1;
    pri['*'] = pri['/'] = pri['%'] = 2;
    pri['^'] = 3;
    string s;
    cin >> s;
    stack<char> q;
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == '(')
            q.push(s[i]);
        else if (s[i] == ')')
        {
            while (!q.empty() && q.top() != '(')
            {
                cout << q.top();
                q.pop();
            }
            q.pop();
        }
        else if (isalpha(s[i]))
            cout << s[i];
        else
        {
            while (!q.empty() && pri[s[i]] <= pri[q.top()] && isOperator(q.top()))
            {
                cout << q.top();
                q.pop();
            }
            q.push(s[i]);
        }
    }
    while (!q.empty() && isOperator(q.top()))
    {
        cout << q.top();
        q.pop();
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
/*
Nếu s[i] là dấu '(' thì push vào stack
Nếu s[i] là dấu ')' thì xuất hết phần tử top của stack bao giờ gặp '(' thì dừng
Nếu s[i] là chữ cái thì in luôn ra màn hình
Nếu s[i] là toán tử thì xét độ ưu tiên với toán tử của phần tử top, nếu s[i]<=top và
top là toán tử thì xuất ra màn hình, sau đó mới push toán tử hiện tại vào stack*/
