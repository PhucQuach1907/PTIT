#include <bits/stdc++.h>
using namespace std;
#define ui64 unsigned long long
#define ll long long
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string s;
        cin >> s;
        set<int> d;
        int diff = 0;
        for (int i = 0; i < s.size(); i++)
            d.insert(s[i]);
        diff = d.size();
        int count[300], tmp = 0, start = 0, res = s.size();
        memset(count, 0, sizeof(count));
        for (int i = 0; i < s.size(); i++)
        {
            count[s[i]]++;
            if (count[s[i]] == 1)
                tmp++;
            if (tmp == diff)
            {
                while (1)
                {
                    if (count[s[start]] > 1)
                    {
                        count[s[start]]--;
                        start++;
                    }
                    else
                        break;
                }
                res = min(res, i - start + 1);
            }
        }
        cout << res << "\n";
    }
    return 0;
}