#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
void Solve()
{
    int n;
    cin >> n;
    priority_queue<int> ans;
    priority_queue<int, vector<int>, greater<int>> one, two;
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        if (x % 3 == 0)
            ans.push(x);
        else if (x % 3 == 1)
            one.push(x);
        else
            two.push(x);
        sum += x;
    }
    bool ok = false;
    if (sum % 3 == 0)
        ok = true;
    else if (sum % 3 == 1)
    {
        if (one.size() > 0)
        {
            one.pop();
            ok = true;
        }
        else if (two.size() > 1)
        {
            two.pop();
            two.pop();
            ok = true;
        }
    }
    else
    {
        if (two.size() > 0)
        {
            two.pop();
            ok = true;
        }
        else if (one.size() > 1)
        {
            one.pop();
            one.pop();
            ok = true;
        }
    }
    if (ok)
    {
        while (!one.empty())
        {
            ans.push(one.top());
            one.pop();
        }
        while (!two.empty())
        {
            ans.push(two.top());
            two.pop();
        }
    }
    if (ans.size() == 0)
        cout << -1 << "\n";
    else if (ans.top() == 0)
        cout << 0 << "\n";
    else
    {
        while (!ans.empty())
        {
            cout << ans.top();
            ans.pop();
        }
        cout << "\n";
    }
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
