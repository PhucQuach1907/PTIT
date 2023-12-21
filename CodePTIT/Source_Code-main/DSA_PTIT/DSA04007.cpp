#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
ll Convert_To_Dec(string s, ll base)
{
    ll ans = 0;
    reverse(s.begin(), s.end());
    for (int i = (int)s.size() - 1; i >= 0; i--)
        ans += pow(base, i) * (s[i] - '0');
    return ans;
}
string Convert_To_Base(ll n, ll base)
{
    string res = "";
    while (n)
    {
        res += to_string(n % base);
        n /= base;
    }
    reverse(res.begin(), res.end());
    return res;
}
void Solve()
{
    string s1, s2;
    ll base;
    cin >> base >> s1 >> s2;
    ll num1 = Convert_To_Dec(s1, base), num2 = Convert_To_Dec(s2, base);
    ll sum = num1 + num2;
    cout << Convert_To_Base(sum, base) << "\n";
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        Solve();
    }
    return 0;
}
