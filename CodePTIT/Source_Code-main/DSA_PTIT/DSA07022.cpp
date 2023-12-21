#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
void Solve()
{
    int n;
    cin >> n;
    unordered_map<int, int> cnt;
    vector<int> a(n), ans(n);
    for (auto &x : a)
    {
        cin >> x;
        cnt[x]++;
    }
    stack<int> stk;
    for (int i = 0; i < n; i++)
    {
        if (stk.empty())
        {
            stk.push(i);
            continue;
        }
        while (!stk.empty() && cnt[a[i]] > cnt[a[stk.top()]])
        {
            ans[stk.top()] = a[i];
            stk.pop();
        }
        stk.push(i);
    }
    while (!stk.empty())
    {
        ans[stk.top()] = -1;
        stk.pop();
    }
    for (int i = 0; i < n; i++)
        cout << ans[i] << " \n"[i == n - 1];
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
