#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
struct Node
{
    string num;
    int r;
};
void Solve()
{
    int n;
    cin >> n;
    queue<Node> q;
    q.push({"1", 1 % n});
    while (!q.empty())
    {
        Node cur = q.front();
        q.pop();
        if (cur.r == 0)
        {
            cout << cur.num << "\n";
            return;
        }
        q.push({cur.num + "0", (cur.r * 10) % n});
        q.push({cur.num + "1", (cur.r * 10 + 1) % n});
    }
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
