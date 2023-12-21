#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
bool Check(vector<int> a, int n)
{
    int sum = 0;
    sum = accumulate(a.begin(), a.end(), sum);
    if (sum & 1)
        return false;
    sum /= 2;
    int dp[5005];
    memset(dp, 0, sizeof(dp));
    dp[0] = 1;
    for (int i = 0; i < n; i++)
        dp[a[i]] = 1;
    for (int i = 0; i < n; i++)
    {
        for (int j = sum; j >= a[i]; j--)
        {
            if (dp[sum - j] == 1)
                dp[j] = 1;
        }
    }
    return (dp[sum] == 1);
}
void Solve()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &c : a)
        cin >> c;
    cout << (Check(a, n) ? "YES" : "NO") << "\n";
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
