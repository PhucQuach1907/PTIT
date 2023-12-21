#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
struct Act
{
    int a, b, c;
};
int main()
{
    int n;
    cin >> n;
    vector<Act> arr(n);
    for (auto &x : arr)
        cin >> x.a >> x.b >> x.c;
    vector<vector<int>> dp(n, vector<int>(3));
    dp[0][0] = arr[0].a, dp[0][1] = arr[0].b, dp[0][2] = arr[0].c;
    for (int i = 1; i < n; i++)
    {
        dp[i][0] = max(dp[i - 1][1], dp[i - 1][2]) + arr[i].a;
        dp[i][1] = max(dp[i - 1][0], dp[i - 1][2]) + arr[i].b;
        dp[i][2] = max(dp[i - 1][0], dp[i - 1][1]) + arr[i].c;
    }
    cout << max({dp[n - 1][0], dp[n - 1][1], dp[n - 1][2]});
    return 0;
}
