#include <bits/stdc++.h>
using namespace std;
#define ui64 unsigned long long
#define ll long long
int main()
{
    int res = 0, step = 0;
    string s;
    cin >> s;
    vector<string> a;
    int start = 0, end;
    for (int i = 0; i < s.size() - 1; i++)
    {
        if (s[i] != s[i + 1])
        {
            end = i;
            a.push_back(s.substr(start, end - start + 1));
            start = i + 1;
        }
    }
    a.push_back(s.substr(start, s.size() - start));
    for (int i = a.size() - 1; i >= 0; i--)
    {
        if ((a[i][0] == 'A' && step % 2 == 0) || (a[i][0] == 'B' && step & 1))
            continue;
        if (a[i].size() == 1)
            res++;
        else
        {
            step++;
            res++;
        }
    }
    cout << res;
    return 0;
}