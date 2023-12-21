#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
void Solve()
{
    int n;
    cin >> n;
    vector<double> a(n), b(n);
    for (int i = 0; i < n; i++)
        cin >> a[i] >> b[i];
    vector<int> dp(n);
    for (int i = 0; i < n; i++)
    {
        dp[i] = 1;
        for (int j = i - 1; j >= 0; j--)
        {
            if (a[i] > a[j] && b[i] < b[j])
                dp[i] = max(dp[i], dp[j] + 1);
        }
    }
    cout << *max_element(dp.begin(), dp.end()) << "\n";
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--)
    {
        Solve();
    }
    return 0;
}
