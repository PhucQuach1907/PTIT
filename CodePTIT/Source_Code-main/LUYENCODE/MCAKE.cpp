#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
bool vis[1005];
int main()
{
    int n, L;
    cin >> n >> L;
    int ans1 = -1, ans2 = -1;
    while (n--)
    {
        int x, y;
        cin >> x >> y;
        ans1 = max(ans1, y - x + 1);
        int tmp = 0;
        for (int i = x; i <= y; i++)
        {
            if (!vis[i])
            {
                tmp++;
                vis[i] = true;
            }
        }
        ans2 = max(ans2, tmp);
    }
    cout << ans1 << " " << ans2;
    return 0;
}
