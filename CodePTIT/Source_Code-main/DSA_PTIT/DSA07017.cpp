#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
void Solve()
{
    int n;
    cin >> n;
    vector<int> a(n), g(n), s(n);
    for (auto &c : a)
        cin >> c;
    stack<int> q;
    for (int i = 0; i < n; i++)
    {
        if (q.empty())
            q.push(i);
        else
        {
            while (!q.empty() && a[i] > a[q.top()])
            {
                g[q.top()] = i;
                q.pop();
            }
            q.push(i);
        }
    }
    while (!q.empty())
    {
        g[q.top()] = -1;
        q.pop();
    }
    stack<int> p;
    for (int i = 0; i < n; i++)
    {
        if (p.empty())
            p.push(i);
        else
        {
            while (!p.empty() && a[i] < a[p.top()])
            {
                s[p.top()] = a[i];
                p.pop();
            }
            p.push(i);
        }
    }
    while (!p.empty())
    {
        s[p.top()] = -1;
        p.pop();
    }
    for (int i = 0; i < n; i++)
        cout << (g[i] != -1 ? s[g[i]] : -1) << " ";
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
