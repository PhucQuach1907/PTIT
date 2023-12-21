#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
void Solve()
{
    int n;
    cin >> n;
    vector<int> a(n), dp(n);
    for (auto &x : a)
        cin >> x;
    for (int i = 0; i < n; i++)
    {
        dp[i] = a[i];
        for (int j = i - 1; j >= 0; j--)
        {
            if (a[i] > a[j])
                dp[i] = max(dp[i], dp[j] + a[i]);
        }
    }
    cout << *max_element(dp.begin(), dp.end()) << "\n";
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
