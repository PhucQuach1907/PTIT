#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
ll th, len[100];
char kthCharacter(ll k, ll th, string s)
{
    if (th == 1)
        return s[--k];
    ll mid = len[th] / 2;
    if (k <= mid)
        return kthCharacter(k, th - 1, s);
    if (k == mid + 1)
        return kthCharacter(len[th - 1], th - 1, s);
    return kthCharacter(k - (mid + 1), th - 1, s);
}
int main()
{
    ll k;
    cin >> k;
    string s;
    cin >> s;
    if ((int)s.size() == 1)
    {
        cout << s[0];
        return 0;
    }
    ll n = s.size();
    len[1] = n;
    for (int i = 2;; i++)
    {
        len[i] = len[i - 1] * 2;
        if (len[i] >= k)
        {
            th = i;
            break;
        }
    }
    cout << kthCharacter(k, th, s);
    return 0;
}
