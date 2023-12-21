#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
struct Node
{
    string str;
    ll step;
};
bool isAdj(string u, string v)
{
    ll dif = 0;
    for (ll i = 0; i < (ll)u.size(); i++)
        dif += (u[i] != v[i]);
    return (dif == 1);
}
void Solve()
{
    ll n;
    string start, end;
    cin >> n >> start >> end;
    set<string> a;
    for (int i = 0; i < n; i++)
    {
        string x;
        cin >> x;
        a.insert(x);
    }
    if (a.find(end) == a.end() || a.find(start) == a.end())
    {
        cout << 0 << "\n";
        return;
    }
    if (start == end)
    {
        cout << 1 << "\n";
        return;
    }
    unordered_map<string, ll> vis_s, vis_e;
    queue<Node> q1, q2;
    q1.push({start, 1});
    q2.push({end, 1});
    vis_s[start] = vis_e[end] = 1;
    while (!q1.empty() && !q2.empty())
    {
        Node cur1 = q1.front();
        q1.pop();
        for (auto x : a)
        {
            if (isAdj(cur1.str, x) && vis_s.count(x) == 0)
            {
                q1.push({x, cur1.step + 1});
                vis_s[x] = cur1.step + 1;
                if (x == end)
                {
                    cout << cur1.step + 1 << "\n";
                    return;
                }
                if (vis_e.count(x))
                {
                    cout << cur1.step + vis_e[x] << "\n";
                    return;
                }
            }
        }
        Node cur2 = q2.front();
        q2.pop();
        for (auto x : a)
        {
            if (isAdj(cur2.str, x) && vis_e.count(x) == 0)
            {
                q2.push({x, cur2.step + 1});
                vis_e[x] = cur2.step + 1;
                if (x == start)
                {
                    cout << cur2.step + 1 << "\n";
                    return;
                }
                if (vis_s.count(x))
                {
                    cout << cur2.step + vis_s[x] << "\n";
                    return;
                }
            }
        }
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll t;
    cin >> t;
    while (t--)
    {
        Solve();
    }
    return 0;
}
