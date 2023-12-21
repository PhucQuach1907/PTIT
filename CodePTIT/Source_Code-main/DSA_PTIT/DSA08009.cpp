#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define ull unsigned long long
struct Node
{
    int val;
    int count;
};
void Solve()
{
    int s, t;
    cin >> s >> t;
    queue<Node> q;
    q.push({s, 0});
    unordered_set<int> diff;
    diff.insert(s);
    while (!q.empty())
    {
        Node temp = q.front();
        q.pop();
        if (temp.val == t)
        {
            cout << temp.count << "\n";
            return;
        }
        if (temp.val - 1 == t || temp.val * 2 == t)
        {
            cout << temp.count + 1 << "\n";
            return;
        }
        if (diff.find(temp.val * 2) == diff.end() && temp.val < t)
        {
            q.push({temp.val * 2, temp.count + 1});
            diff.insert(temp.val * 2);
        }
        if (diff.find(temp.val - 1) == diff.end() && temp.val > 1)
        {
            q.push({temp.val - 1, temp.count + 1});
            diff.insert(temp.val - 1);
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
