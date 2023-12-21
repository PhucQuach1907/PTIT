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
        cout << (s[s.size() - 1] == '6' && s[s.size() - 2] == '8') << "\n";
    }
    return 0;
}