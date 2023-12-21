#include <bits/stdc++.h>
using namespace std;
#define ui64 unsigned long long
#define ll long long
const int MAX = 1e5 + 5;
int String_To_Number(string s)
{
    int res = 0;
    for (int i = 0; i < s.size(); i++)
        res = res * 10 + (s[i] - '0');
    return res;
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int ans = 0;
        char s[MAX];
        vector<string> num;
        cin >> s;
        char *p = strtok(s, "abcdefghijklmnopqrstuvwxyz");
        while (p != NULL)
        {
            num.push_back(p);
            p = strtok(NULL, "abcdefghijklmnopqrstuvwxyz");
        }
        for (auto c : num)
            ans += String_To_Number(c);
        cout << ans << "\n";
    }
    return 0;
}