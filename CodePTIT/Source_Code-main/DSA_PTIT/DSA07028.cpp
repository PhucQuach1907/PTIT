#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
void Solve()
{
    int n;
    cin >> n;
    vector<int> a(n), res(n);
    for (auto &x : a)
        cin >> x;
    stack<int> stk;
    for (int i = 0; i < n; i++)
    {
        int cnt = 1;
        while (!stk.empty() && a[i] >= a[stk.top()])
        {
            cnt += res[stk.top()];
            stk.pop();
        }
        res[i] = cnt;
        stk.push(i);
    }
    for (int i = 0; i < n; i++)
        cout << res[i] << " \n"[i == n - 1];
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
