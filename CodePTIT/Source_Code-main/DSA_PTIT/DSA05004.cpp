#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
int main()
{
    int n;
    cin >> n;
    vector<int> a(n), dp(n, 1);
    for (auto &x : a)
        cin >> x;
    dp[0] = 1;
    for (int i = 1; i < n; i++)
    {
        for (int j = i - 1; j >= 0; j--)
        {
            if (a[i] > a[j])
                dp[i] = max(dp[i], dp[j] + 1);
        }
    }
    cout << *max_element(dp.begin(), dp.end());
    return 0;
}
