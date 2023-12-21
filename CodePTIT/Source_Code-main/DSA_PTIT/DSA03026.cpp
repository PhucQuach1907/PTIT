#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
string Find_Min(int s, int d)
{
    if (s > 9 * d || s == 0)
        return "-1";
    stack<int> stk;
    while (s > 9)
    {
        stk.push(9);
        s -= 9;
        d--;
    }
    stk.push(s);
    d--;
    if (d > 0)
    {
        int cur = stk.top();
        stk.pop();
        stk.push(--cur);
        while (d > 1)
        {
            stk.push(0);
            d--;
        }
        stk.push(1);
    }
    string ans = "";
    while (!stk.empty())
    {
        ans += to_string(stk.top());
        stk.pop();
    }
    return ans;
}
string Find_Max(int s, int d)
{
    if (s > 9 * d || s == 0)
        return "-1";
    stack<int> stk;
    while (s > 9)
    {
        stk.push(9);
        s -= 9;
        d--;
    }
    if (d > 0)
    {
        stk.push(s);
        d--;
    }
    while (d--)
        stk.push(0);
    string res = "";
    while (!stk.empty())
    {
        res += to_string(stk.top());
        stk.pop();
    }
    reverse(res.begin(), res.end());
    return res;
}
int main()
{
    int s, d;
    cin >> d >> s;
    cout << Find_Min(s, d) << " " << Find_Max(s, d);
    return 0;
}
