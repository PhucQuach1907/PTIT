#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
void Solve()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &x : a)
        cin >> x;
    stack<int> stk;
    vector<int> res(n);
    for (int i = 0; i < n; i++)
    {
        while (!stk.empty() && a[i] > a[stk.top()])
        {
            res[stk.top()] = a[i];
            stk.pop();
        }
        stk.push(i);
    }
    while (!stk.empty())
    {
        res[stk.top()] = -1;
        stk.pop();
    }
    for (int i = 0; i < n; i++)
        cout << res[i] << " \n"[i == n - 1];
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
