#include <bits/stdc++.h>
using namespace std;
#define ui64 unsigned long long
string Sum(string x, string y)
{
    string ans;
    if (x.size() < y.size())
        swap(x, y);
    y.insert(0, x.size() - y.size(), '0');
    int remain = 0;
    for (int i = x.size() - 1; i >= 0; i--)
    {
        int tmp = (x[i] - '0') + (y[i] - '0') + remain;
        ans += to_string(tmp % 10);
        remain = tmp / 10;
    }
    reverse(ans.begin(), ans.end());
    if (remain == 1)
        ans.insert(0, 1, '1');
    return ans;
}
bool isSumString(string s, int start, int len1, int len2)
{
    string s1 = s.substr(start, len1);
    string s2 = s.substr(start + len1, len2);
    string s3 = Sum(s1, s2);
    if (s3.size() > s.size() - start - len1 - len2)
        return 0;
    if (s3 == s.substr(start + len1 + len2, s3.size()))
    {
        if (start + len1 + len2 + s3.size() == s.size())
            return 1;
        return isSumString(s, start + len1, len2, s3.size());
    }
    return 0;
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string s;
        cin >> s;
        int ok = 0;
        for (int i = 1; i < s.size(); i++)
        {
            for (int j = 1; i + j < s.size(); j++)
            {
                if (isSumString(s, 0, i, j))
                {
                    ok = 1;
                    break;
                }
            }
        }
        cout << (ok == 1 ? "Yes\n" : "No\n");
    }
    return 0;
}