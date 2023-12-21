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
        string s, res;
        cin >> s;
        int sum = 0;
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] >= '0' && s[i] <= '9')
                sum += (s[i] - '0');
            else
                res += s[i];
        }
        sort(res.begin(), res.end());
        cout << res << sum << "\n";
    }
    return 0;
}