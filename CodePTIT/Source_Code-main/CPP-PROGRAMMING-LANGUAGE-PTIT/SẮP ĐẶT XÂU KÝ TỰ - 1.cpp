#include <bits/stdc++.h>
using namespace std;
#define ui64 unsigned long long
#define ll long long
int Arrange(string s)
{
    int a[125];
    memset(a, 0, sizeof(a));
    for (int i = 0; i < s.size(); i++)
        a[s[i]]++;
    if (s.size() & 1)
    {
        for (int i = 97; i <= 122; i++)
        {
            if (a[i] > s.size() / 2 + 1)
                return 0;
        }
    }
    else
    {
        for (int i = 97; i <= 122; i++)
        {
            if (a[i] > s.size() / 2)
                return 0;
        }
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
        cout << Arrange(s) << "\n";
    }
    return 0;
}