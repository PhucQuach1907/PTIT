#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
ll Palindrome(string pref, ll numlength)
{
    string ans = pref;
    if (numlength & 1)
        pref.pop_back();
    reverse(pref.begin(), pref.end());
    ans += pref;
    return stoll(ans);
}
ll Count(string s)
{
    ll n = s.size();
    if (n == 1)
        return stoll(s);
    ll mid = (n + 1) / 2;
    string pref = s.substr(0, mid);
    if (Palindrome(pref, n) > stoll(s))
        pref = to_string(stoll(pref) - 1);
    ll prefix_num = stoll(pref), prefix_length = pref.size();
    return (n & 1 ? prefix_num + pow(10, prefix_length - 1) - 1 : 2 * prefix_num + pow(10, prefix_length) - 1 - prefix_num);
}
int main()
{
    ll l, r;
    while (cin >> l >> r)
    {
        l--;
        cout << (Count(to_string(r)) - Count(to_string(l))) << "\n";
    }
    return 0;
}
