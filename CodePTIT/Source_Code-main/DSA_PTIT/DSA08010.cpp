#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define ull unsigned long long
struct Node
{
    int val;
    int step;
};
void Solve()
{
    int n;
    cin >> n;
    unordered_set<int> s;
    queue<Node> q;
    q.push({n, 0});
    s.insert(n);
    while (!q.empty())
    {
        Node cur = q.front();
        q.pop();
        if (cur.val == 1)
        {
            cout << cur.step << "\n";
            return;
        }
        if (s.find(cur.val - 1) == s.end() && cur.val - 1 > 0)
        {
            q.push({cur.val - 1, cur.step + 1});
            s.insert(cur.val - 1);
        }
        for (int i = 2; i <= sqrt(cur.val); i++)
        {
            if (cur.val % i == 0)
            {
                if (s.find(cur.val / i) == s.end())
                {
                    q.push({cur.val / i, cur.step + 1});
                    s.insert(cur.val / i);
                }
            }
        }
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
