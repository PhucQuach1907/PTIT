#include <bits/stdc++.h>
using namespace std;
#define ui64 unsigned long long
#define ll long long
bool isZeroString(string s)
{
    int zero = 0;
    for (int i = 0; i < s.size(); i++)
        zero += (s[i] == '0' ? 1 : 0);
    return (zero == s.size());
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string s, res = "", tmp="";
        cin >> s;
        if (isZeroString(s))
        {
            cout << "\n";
            continue;
        }
        int count[11];
        memset(count, 0, sizeof(count));
        for (int i = 0; i < s.size(); i++)
            count[s[i] - '0']++;
        vector<pair<int, int>> a;
        for (int i = 0; i < 10; i++)
        {
            if (count[i] % 2 == 0 && count[i] != 0)
                a.push_back({i, count[i]});
        }
        if (a.size() == 0)
        {
            int len = 0, num = 1;
            for (int i = 9; i > 0; i--)
            {
                if (count[i] > len && (count[i] & 1))
                {
                    len = count[i];
                    num = i;
                }
            }
            res.insert(res.size(), len, num + '0');
        }
        else
        {
            int len = 0, num = 1;
            for (int i = 9; i >= 0; i--)
            {
                if (count[i] > len && (count[i] & 1))
                {
                    len = count[i];
                    num = i;
                }
            }
            if (len)
                tmp.insert(tmp.size(), len, num + '0');
            sort(a.rbegin(), a.rend());
            for (int i = 0; i < a.size(); i++)
                res.insert(res.size(), a[i].second / 2, a[i].first + '0');
            string tg = res;
            tg+=tmp;
            reverse(res.begin(), res.end());
            res = tg + res;
            while (res[0] == '0')
            {
                res.erase(0, 1);
                res.erase(res.size() - 1, 1);
            }
        }
        cout << res << "\n";
    }
    return 0;
}