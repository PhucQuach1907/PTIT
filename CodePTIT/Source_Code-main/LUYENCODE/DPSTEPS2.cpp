#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
string operator+(string x, string y)
{
    string ans;
    if (x.size() < y.size())
        swap(x, y);
    y.insert(0, x.size() - y.size(), '0');
    int a[x.size()], b[y.size()], sum[x.size()];
    memset(a, 0, sizeof(a));
    memset(b, 0, sizeof(b));
    memset(sum, 0, sizeof(sum));
    for (int i = 0; i < x.size(); i++)
        a[i] = x[i] - '0';
    for (int i = 0; i < y.size(); i++)
        b[i] = y[i] - '0';
    int remain = 0;
    for (int i = x.size() - 1; i >= 0; i--)
    {
        int tmp = a[i] + b[i] + remain;
        sum[i] = (i == 0 ? tmp : tmp % 10);
        remain = tmp / 10;
    }
    for (int i = 0; i < x.size(); i++)
        ans += to_string(sum[i]);
    return ans;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, k;
    cin >> n >> k;
    vector<bool> isBroken(n + 1, 0);
    for (int i = 0; i < k; i++)
    {
        int x;
        cin >> x;
        isBroken[x] = 1;
    }
    vector<string> dp(n + 1);
    dp[1] = (isBroken[1] ? "0" : "1");
    dp[2] = (isBroken[2] ? "0" : to_string(1) + dp[1]);
    for (int i = 3; i <= n; i++)
        dp[i] = (!isBroken[i - 1] ? dp[i - 1] : "0") + (!isBroken[i - 2] ? dp[i - 2] : "0");
    cout << dp[n];
    return 0;
}
