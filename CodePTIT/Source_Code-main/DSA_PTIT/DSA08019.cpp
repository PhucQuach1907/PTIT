#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
void Solve()
{
    int n;
    cin >> n;
    vector<string> ans;
    queue<string> q;
    q.push("6");
    q.push("8");
    while (!q.empty())
    {
        string cur = q.front();
        q.pop();
        if ((int)cur.size() > n)
            break;
        ans.push_back(cur);
        q.push(cur + "6");
        q.push(cur + "8");
    }
    cout << ans.size() << "\n";
    for (int i = (int)ans.size() - 1; i >= 0; i--)
        cout << ans[i] << " \n"[i == 0];
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
