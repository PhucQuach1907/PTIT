#include <bits/stdc++.h>
using namespace std;
#define ui64 unsigned long long
#define ll long long
bool check(string s)
{
    for (int i = 1; i < s.size(); i++)
    {
        if (abs((s[i] - '0') - (s[i - 1] - '0')) != 1)
            return 0;
    }
    return 1;
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string s;
        cin >> s;
        cout << (check(s) ? "YES\n" : "NO\n");
    }
    return 0;
}