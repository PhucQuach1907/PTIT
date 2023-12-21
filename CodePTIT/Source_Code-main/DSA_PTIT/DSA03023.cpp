#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
int Find_Pos(int n, int start, int end, string s, char c)
{
    for (int i = start; i <= end; i++)
    {
        if (s[i] == c)
            return i;
    }
    for (int i = n - 1; i >= 0; i--)
    {
        if (s[i] == c)
            return i;
    }
}
int main()
{
    int n;
    string s;
    cin >> n >> s;
    string target = s;
    sort(target.rbegin(), target.rend());
    int start_x = target.find('X'), end_x = target.rfind('X');
    int start_t = target.find('T'), end_t = target.rfind('T');
    int start_d = target.find('D'), end_d = target.rfind('D');
    int res = 0;
    for (int i = 0; i < n; i++)
    {
        if (s[i] == target[i])
            continue;
        int pos;
        if (s[i] == 'X')
            pos = Find_Pos(n, start_x, end_x, s, target[i]);
        else if (s[i] == 'T')
            pos = Find_Pos(n, start_t, end_t, s, target[i]);
        else
            pos = Find_Pos(n, start_d, end_d, s, target[i]);
        swap(s[pos], s[i]);
        res++;
    }
    cout << res;
    return 0;
}
