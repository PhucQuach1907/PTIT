#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
int main()
{
    string s;
    cin >> s;
    int cur_pos[200];
    memset(cur_pos, -1, sizeof(cur_pos));
    int start = 0, ans = -1;
    for (int i = 0; i < (int)s.size(); i++)
    {
        start = max(start, cur_pos[s[i]] + 1);
        ans = max(ans, i - start + 1);
        cur_pos[s[i]] = i;
    }
    cout << ans;
    return 0;
}
