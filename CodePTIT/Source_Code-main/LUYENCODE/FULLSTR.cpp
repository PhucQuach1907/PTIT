#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
int main()
{
    int cnt[200] = {0};
    string s;
    cin >> s;
    int start = 0, ans = INT_MAX, cur = 0;
    for (int i = 0; i < (int)s.size(); i++)
    {
        cnt[s[i]]++;
        if (cnt[s[i]] == 1)
            cur++;
        if (cur == 26)
        {
            while (cnt[s[start]] > 1)
            {
                cnt[s[start]]--;
                start++;
            }
            ans = min(ans, i - start + 1);
        }
    }
    cout << (ans == INT_MAX ? -1 : ans);
    return 0;
}
