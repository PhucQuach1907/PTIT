#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
struct Data
{
    int num, cnt;
};
void Solve()
{
    int n;
    cin >> n;
    queue<Data> q;
    q.push({n, 0});
    set<int> s;
    s.insert(n);
    while (!q.empty())
    {
        Data tmp = q.front();
        if (tmp.num == 1)
        {
            cout << tmp.cnt << "\n";
            return;
        }
        q.pop();
        int m1 = tmp.num - 1;
        if (s.find(m1) == s.end())
            q.push({m1, tmp.cnt + 1});
        if (tmp.num % 2 == 0)
        {
            int m2 = tmp.num / 2;
            if (s.find(m2) == s.end())
                q.push({m2, tmp.cnt + 1});
        }
        if (tmp.num % 3 == 0)
        {
            int m3 = tmp.num / 3;
            if (s.find(m3) == s.end())
                q.push({m3, tmp.cnt + 1});
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
