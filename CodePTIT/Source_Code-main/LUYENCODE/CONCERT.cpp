#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
void SetUp(vector<int> a, int n, vector<int> &l, vector<int> &r, vector<int> &equal)
{
    stack<int> stk;
    for (int i = 0; i < n; i++)
    {
        if (stk.empty())
        {
            stk.push(i);
            continue;
        }
        while (!stk.empty() && a[i] > a[stk.top()])
        {
            r[stk.top()] = i;
            stk.pop();
        }
        stk.push(i);
    }
    while (!stk.empty())
    {
        r[stk.top()] = -1;
        stk.pop();
    }
    for (int i = n - 1; i >= 0; i--)
    {
        if (stk.empty())
        {
            stk.push(i);
            continue;
        }
        while (!stk.empty() && a[i] > a[stk.top()])
        {
            l[stk.top()] = i;
            stk.pop();
        }
        stk.push(i);
    }
    while (!stk.empty())
    {
        l[stk.top()] = -1;
        stk.pop();
    }
    for (int i = 0; i < n; i++)
    {
        l[i] = (l[i] == -1 ? 0 : 1);
        r[i] = (r[i] == -1 ? 0 : 1);
    }
    equal[0] = 0;
    for (int i = 1; i < n; i++)
        equal[i] = (a[i] == a[i - 1] ? equal[i - 1] + 1 : 0);
}
int main()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &x : a)
        cin >> x;
    vector<int> l(n), r(n), equal(n);
    SetUp(a, n, l, r, equal);
    ll res = 0;
    for (int i = 0; i < n; i++)
        res += (l[i] + r[i] + equal[i]);
    cout << res;
    return 0;
}
