#include <bits/stdc++.h>
using namespace std;
#define ui64 unsigned long long
#define ll long long
const int MAX = 1e5 + 5;
bool cmp(string a, string b)
{
    if (a.size() != b.size())
        return a.size() < b.size();
    return a < b;
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
        for (int i = 0; i < num.size(); i++)
        {
            while (num[i][0] == '0')
                num[i].erase(0, 1);
            if (num[i].size() == 0)
                num[i] = "0";
        }
        sort(num.begin(), num.end(), cmp);
        cout << num[num.size() - 1] << "\n";
    }
    return 0;
}