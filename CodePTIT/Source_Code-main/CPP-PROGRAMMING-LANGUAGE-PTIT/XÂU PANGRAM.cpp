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
        int k, shortage = 0;
        cin >> s >> k;
        int a[125];
        memset(a, 0, sizeof(a));
        for (int i = 0; i < s.size(); i++)
            a[(int)s[i]]++;
        for (int i = 97; i <= 122; i++)
            shortage += (a[i] == 0 ? 1 : 0);
        cout << (k >= shortage) << "\n";
    }
    return 0;
}