#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
ll Bin_To_Dec(string s)
{
    reverse(s.begin(), s.end());
    ll ans = 0;
    for (ll i = 0; i < s.size(); i++)
        ans += (s[i] - '0') * pow(2, i);
    return ans;
}
void Solve()
{
    string s1, s2;
    cin >> s1 >> s2;
    ll num1 = Bin_To_Dec(s1), num2 = Bin_To_Dec(s2);
    ll ans = num1 * num2;
    cout << ans << "\n";
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
