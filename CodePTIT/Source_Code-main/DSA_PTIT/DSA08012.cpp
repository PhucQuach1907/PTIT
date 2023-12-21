#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define ull unsigned long long
bool isNotExist(int num, int digit)
{
    string s = to_string(num);
    return (s.find(digit + '0') == -1);
}
void Solve()
{
    int l, r;
    cin >> l >> r;
    int ans = (l == 0 ? 1 : 0);
    queue<int> q;
    q.push(0);
    while (!q.empty())
    {
        int cur = q.front();
        q.pop();
        if (cur >= l && cur <= r && cur != 0)
            ans++;
        if (cur > r)
            break;
        for (int i = 0; i < 6; i++)
        {
            if (isNotExist(cur, i))
                q.push(cur * 10 + i);
        }
    }
    cout << ans << "\n";
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
