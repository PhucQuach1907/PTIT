#include <bits/stdc++.h>
using namespace std;
bool check(string s1, string s2)
{
    for (int i = 0; i < s2.size(); i++)
    {
        int pos = s1.find(s2[i]);
        if (pos == -1)
            return 0;
        s1.erase(pos, 1);
    }
    return 1;
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string s1, s2, tmp, ans;
        cin >> s1 >> s2;
        ans = s1;
        if (!check(s1, s2))
            cout << -1 << "\n";
        else
        {
            for (int i = 0; i < s1.size(); i++)
            {
                tmp += s1[i];
                if (check(tmp, s2))
                {
                    while (1)
                    {
                        string tg = tmp;
                        tg.erase(0, 1);
                        if (!check(tg, s2))
                            break;
                        tmp.erase(0, 1);
                    }
                    if (tmp.size() < ans.size())
                        ans = tmp;
                }
            }
            cout << ans << "\n";
        }
    }
    return 0;
}