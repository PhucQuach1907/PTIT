#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
void Solve()
{
    ull n;
    cin >> n;
    queue<ull> q;
    q.push(1);
    int res = 0;
    while (q.front() <= n)
    {
        res++;
        ull cur = q.front();
        q.pop();
        q.push(cur * 10);
        q.push(cur * 10 + 1);
    }
    cout << res << "\n";
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--)
    {
        Solve();
    }
    return 0;
}
