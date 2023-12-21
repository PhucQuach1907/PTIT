#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
int n;
vector<ll> a(1005);
vector<vector<ll>> dp(1005, vector<ll>(1005, INT_MAX));
int main()
{
    cin >> n;
    int voucher = 0;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    dp[1][0] = a[1];
    dp[1][1] = (a[1] > 100 ? a[1] : INT_MAX);
    for (int i = 2; i <= n; i++)
    {
        for (int j = 0; j < 1005; j++)
        {
            dp[i][j] = min({dp[i][j], dp[i - 1][j + 1], dp[i - 1][j] + a[i]});
            if (a[i] > 100 && j > 0)
                dp[i][j] = min(dp[i][j], dp[i - 1][j - 1] + a[i]);
        }
    }
    cout << dp[n][0];
    return 0;
}
//dp[i][j]: số tiền nhỏ nhất phải trả từ sản phẩm thứ 1 đến sản phẩm thứ i và còn lại j voucher
