#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
const int MAX = 1e4 + 5;
vector<bool> isPrime(MAX, true);
vector<int> Prime;
vector<int> adj[MAX];
bool isAdj(int a, int b)
{
    string s = to_string(a), ss = to_string(b);
    int diff = 0;
    for (int i = 0; i < 4; i++)
        diff += (s[i] != ss[i]);
    return (diff == 1);
}
void SetUp()
{
    isPrime[0] = isPrime[1] = false;
    for (int i = 2; i <= MAX / 2; i++)
    {
        if (isPrime[i])
        {
            for (int j = 2 * i; j < MAX; j += i)
                isPrime[j] = false;
        }
    }
    for (int i = 1000; i < 10000; i++)
    {
        if (isPrime[i])
            Prime.push_back(i);
    }
    for (int i = 0; i < (int)Prime.size() - 1; i++)
    {
        for (int j = i + 1; j < (int)Prime.size(); j++)
        {
            if (isAdj(Prime[i], Prime[j]))
            {
                adj[Prime[i]].push_back(Prime[j]);
                adj[Prime[j]].push_back(Prime[i]);
            }
        }
    }
}
struct Node
{
    int val, step;
};
void Solve()
{
    int s, t;
    cin >> s >> t;
    vector<bool> vis(MAX, false);
    queue<Node> q;
    q.push({s, 0});
    vis[s] = true;
    while (!q.empty())
    {
        Node cur = q.front();
        q.pop();
        if (cur.val == t)
        {
            cout << cur.step << "\n";
            return;
        }
        for (auto x : adj[cur.val])
        {
            if (!vis[x])
            {
                vis[x] = true;
                q.push({x, cur.step + 1});
            }
        }
    }
}
int main()
{
    SetUp();
    int t;
    cin >> t;
    while (t--)
    {
        Solve();
    }
    return 0;
}
