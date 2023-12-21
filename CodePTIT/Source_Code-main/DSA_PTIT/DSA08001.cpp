#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
void Solve()
{
    int n;
    cin >> n;
    queue<int> q;
    while (n--)
    {
        int x;
        cin >> x;
        if (x == 3)
        {
            int num;
            cin >> num;
            q.push(num);
        }
        else
        {
            if (x == 1)
                cout << q.size() << "\n";
            else if (x == 2)
                cout << (q.empty() ? "YES\n" : "NO\n");
            else if (x == 4)
            {
                if (!q.empty())
                    q.pop();
            }
            else if (x == 5)
                cout << (q.empty() ? -1 : q.front()) << "\n";
            else
                cout << (q.empty() ? -1 : q.back()) << "\n";
        }
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
