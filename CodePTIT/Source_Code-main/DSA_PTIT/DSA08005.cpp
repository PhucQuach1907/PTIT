#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
void Solve()
{
    int n;
    cin >> n;
    queue<string> q;
    q.push("1");
    while (!q.empty() && n--)
    {
        string cur = q.front();
        q.pop();
        cout << cur << " ";
        q.push(cur + "0");
        q.push(cur + "1");
    }
    cout << "\n";
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
